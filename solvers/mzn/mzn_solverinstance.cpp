/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
 *  Main authors:
 *     Guido Tack <guido.tack@monash.edu>
 */

 /* This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifdef _WIN32
#define NOMINMAX     // Need this before all (implicit) include's of Windows.h
#endif

#include <minizinc/solvers/mzn_solverinstance.hh>
#include <cstdio>
#include <fstream>

#include <minizinc/timer.hh>
#include <minizinc/process.hh>

using namespace std;

namespace MiniZinc {
  
  MZN_SolverFactory::MZN_SolverFactory(void) {
    SolverConfig sc("org.minizinc.mzn-mzn",MZN_VERSION_MAJOR "." MZN_VERSION_MINOR "." MZN_VERSION_PATCH);
    sc.name("Generic MiniZinc driver");
    sc.mznlibVersion(1);
    sc.description("MiniZinc generic MiniZinc solver plugin");
    sc.requiredFlags({"-m"});
    sc.supportsFzn(false);
    sc.supportsMzn(true);
    sc.needsSolns2Out(false);
    SolverConfigs::registerBuiltinSolver(sc);
  }
  
  string MZN_SolverFactory::getDescription(SolverInstanceBase::Options*)  {
    string v = "MZN solver plugin, compiled  " __DATE__ "  " __TIME__;
    return v;
  }


  string MZN_SolverFactory::getVersion(SolverInstanceBase::Options*) {
    return MZN_VERSION_MAJOR;
  }

  string MZN_SolverFactory::getId()
  {
    return "org.minizinc.mzn-mzn";
  }
  
  void MZN_SolverFactory::printHelp(ostream& os)
  {
    os
    << "MZN-MZN plugin options:" << std::endl
    << "  -m, --minizinc-cmd <exe>\n     the backend solver filename.\n"
    << "  --mzn-flags <options>, --minizinc-flags <options>\n     Specify option to be passed to the MiniZinc interpreter.\n"
    << "  --mzn-flag <option>, --minizinc-flag <option>\n     As above, but for a single option string that need to be quoted in a shell.\n"
    << "  --mzn-time-limit <ms>\n     Set a hard timelimit that overrides those set for the solver using --mzn-flag(s).\n"
    << "  --mzn-sigint\n     Send SIGINT instead of SIGTERM.\n"
    ;
  }

  SolverInstanceBase::Options* MZN_SolverFactory::createOptions(void) {
    return new MZNSolverOptions;
  }

  SolverInstanceBase* MZN_SolverFactory::doCreateSI(Env& env, std::ostream& log, SolverInstanceBase::Options* opt) {
    return new MZNSolverInstance(env, log, opt);
  }

  bool MZN_SolverFactory::processOption(SolverInstanceBase::Options* opt, int& i, std::vector<std::string>& argv)
  {
    MZNSolverOptions& _opt = static_cast<MZNSolverOptions&>(*opt);
    CLOParser cop( i, argv );
    string buffer;
    int nn=-1;
    
    if ( cop.getOption( "-m --minizinc-cmd", &buffer) ) {
      _opt.mzn_solver = buffer;
    } else if ( cop.getOption( "--mzn-flags --minizinc-flags", &buffer) ) {
      string old = _opt.mzn_flags;
      old += ' ';
      old += buffer;
      _opt.mzn_flags = old;
    } else if ( cop.getOption( "--mzn-time-limit", &nn) ) {
      _opt.mzn_time_limit_ms = nn;
    } else if ( cop.getOption( "--mzn-sigint") ) {
      _opt.mzn_sigint = true;
    } else if ( cop.getOption( "--mzn-flag --minizinc-flag", &buffer) ) {
      string old = _opt.mzn_flag;
      old += " \"";
      old += buffer;
      old += "\" ";
      _opt.mzn_flag = old;
    } else {
      std::string input_file(argv[i]);
      if (input_file.length()<=4) {
        // std::cerr << "Error: cannot handle file " << input_file << "." << std::endl;
        return false;
      }
      size_t last_dot = input_file.find_last_of('.');
      if (last_dot == string::npos) {
        return false;
      }
      std::string extension = input_file.substr(last_dot,string::npos);
      if (extension == ".mzn" || extension ==  ".mzc" || extension == ".fzn" || extension == ".dzn" || extension == ".json") {
        string old = _opt.mzn_flags;
        old += ' ';
        old += input_file;
        _opt.mzn_flags = old;
      } else {
        return false;
      }
    }
    return true;
  }
  


  MZNSolverInstance::MZNSolverInstance(Env& env, std::ostream& log, SolverInstanceBase::Options* options)
    : SolverInstanceBase(env, log, options) {}

  MZNSolverInstance::~MZNSolverInstance(void) {}

  class Solns2Log {
  private:
    std::ostream& _log;
  public:
    Solns2Log(std::ostream& log) : _log(log) {}
    bool feedRawDataChunk(const char* data) { _log << data; return true; }
  };
  
  SolverInstance::Status
  MZNSolverInstance::solve(void) {
    MZNSolverOptions& opt = static_cast<MZNSolverOptions&>(*_options);
    if (opt.mzn_solver.empty()) {
      throw InternalError("No MiniZinc solver specified");
    }
    /// Passing options to solver
    vector<string> cmd_line;
    cmd_line.push_back( opt.mzn_solver );
    string sFlags = opt.mzn_flags;
    if ( sFlags.size() )
      cmd_line.push_back( sFlags );
    string sFlagQuoted = opt.mzn_flag;
    if ( sFlagQuoted.size() )
      cmd_line.push_back( sFlagQuoted );
    if (opt.printStatistics) {
      cmd_line.push_back( "-s" );
    }
    if (opt.verbose) {
      cmd_line.push_back( "-v" );
      std::cerr << "Using MZN solver " << cmd_line[0]
        << " for solving, parameters: ";
      for ( int i=1; i<cmd_line.size(); ++i )
        cerr << "" << cmd_line[i] << " ";
      cerr << std::endl;
    }
    int timelimit = opt.mzn_time_limit_ms;
    bool sigint = opt.mzn_sigint;
    
    Solns2Log s2l(_log);
    Process<Solns2Log> proc(cmd_line, &s2l, timelimit, sigint);
    proc.run();

    return SolverInstance::UNKNOWN;
  }

  void MZNSolverInstance::processFlatZinc(void) {}

  void MZNSolverInstance::resetSolver(void) {}

}