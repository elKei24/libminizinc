/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_USERS_JDEKKER_REPOSITORIES_MINIZINC_LIBMZN_BUILD_MINIZINC_PARSER_TAB_HH_INCLUDED
# define YY_YY_USERS_JDEKKER_REPOSITORIES_MINIZINC_LIBMZN_BUILD_MINIZINC_PARSER_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    MZN_INTEGER_LITERAL = 258,
    MZN_BOOL_LITERAL = 259,
    MZN_FLOAT_LITERAL = 260,
    MZN_IDENTIFIER = 261,
    MZN_QUOTED_IDENTIFIER = 262,
    MZN_STRING_LITERAL = 263,
    MZN_STRING_QUOTE_START = 264,
    MZN_STRING_QUOTE_MID = 265,
    MZN_STRING_QUOTE_END = 266,
    MZN_TI_IDENTIFIER = 267,
    MZN_TI_ENUM_IDENTIFIER = 268,
    MZN_DOC_COMMENT = 269,
    MZN_DOC_FILE_COMMENT = 270,
    MZN_VAR = 271,
    MZN_PAR = 272,
    MZN_ABSENT = 273,
    MZN_ANN = 274,
    MZN_ANNOTATION = 275,
    MZN_ANY = 276,
    MZN_ARRAY = 277,
    MZN_BOOL = 278,
    MZN_CASE = 279,
    MZN_CONSTRAINT = 280,
    MZN_DEFAULT = 281,
    MZN_ELSE = 282,
    MZN_ELSEIF = 283,
    MZN_ENDIF = 284,
    MZN_ENUM = 285,
    MZN_FLOAT = 286,
    MZN_FUNCTION = 287,
    MZN_IF = 288,
    MZN_INCLUDE = 289,
    MZN_INFINITY = 290,
    MZN_INT = 291,
    MZN_LET = 292,
    MZN_LIST = 293,
    MZN_MAXIMIZE = 294,
    MZN_MINIMIZE = 295,
    MZN_OF = 296,
    MZN_OPT = 297,
    MZN_SATISFY = 298,
    MZN_OUTPUT = 299,
    MZN_PREDICATE = 300,
    MZN_RECORD = 301,
    MZN_SET = 302,
    MZN_SOLVE = 303,
    MZN_STRING = 304,
    MZN_TEST = 305,
    MZN_THEN = 306,
    MZN_TUPLE = 307,
    MZN_TYPE = 308,
    MZN_UNDERSCORE = 309,
    MZN_VARIANT_RECORD = 310,
    MZN_WHERE = 311,
    MZN_LEFT_BRACKET = 312,
    MZN_LEFT_2D_BRACKET = 313,
    MZN_RIGHT_BRACKET = 314,
    MZN_RIGHT_2D_BRACKET = 315,
    FLATZINC_IDENTIFIER = 316,
    MZN_INVALID_INTEGER_LITERAL = 317,
    MZN_INVALID_FLOAT_LITERAL = 318,
    MZN_UNTERMINATED_STRING = 319,
    MZN_INVALID_NULL = 320,
    MZN_EQUIV = 321,
    MZN_IMPL = 322,
    MZN_RIMPL = 323,
    MZN_OR = 324,
    MZN_XOR = 325,
    MZN_AND = 326,
    MZN_LE = 327,
    MZN_GR = 328,
    MZN_LQ = 329,
    MZN_GQ = 330,
    MZN_EQ = 331,
    MZN_NQ = 332,
    MZN_IN = 333,
    MZN_SUBSET = 334,
    MZN_SUPERSET = 335,
    MZN_UNION = 336,
    MZN_DIFF = 337,
    MZN_SYMDIFF = 338,
    MZN_DOTDOT = 339,
    MZN_PLUS = 340,
    MZN_MINUS = 341,
    MZN_MULT = 342,
    MZN_DIV = 343,
    MZN_IDIV = 344,
    MZN_MOD = 345,
    MZN_INTERSECT = 346,
    MZN_NOT = 347,
    MZN_PLUSPLUS = 348,
    MZN_COLONCOLON = 349,
    PREC_ANNO = 350,
    MZN_EQUIV_QUOTED = 351,
    MZN_IMPL_QUOTED = 352,
    MZN_RIMPL_QUOTED = 353,
    MZN_OR_QUOTED = 354,
    MZN_XOR_QUOTED = 355,
    MZN_AND_QUOTED = 356,
    MZN_LE_QUOTED = 357,
    MZN_GR_QUOTED = 358,
    MZN_LQ_QUOTED = 359,
    MZN_GQ_QUOTED = 360,
    MZN_EQ_QUOTED = 361,
    MZN_NQ_QUOTED = 362,
    MZN_IN_QUOTED = 363,
    MZN_SUBSET_QUOTED = 364,
    MZN_SUPERSET_QUOTED = 365,
    MZN_UNION_QUOTED = 366,
    MZN_DIFF_QUOTED = 367,
    MZN_SYMDIFF_QUOTED = 368,
    MZN_DOTDOT_QUOTED = 369,
    MZN_PLUS_QUOTED = 370,
    MZN_MINUS_QUOTED = 371,
    MZN_MULT_QUOTED = 372,
    MZN_DIV_QUOTED = 373,
    MZN_IDIV_QUOTED = 374,
    MZN_MOD_QUOTED = 375,
    MZN_INTERSECT_QUOTED = 376,
    MZN_NOT_QUOTED = 377,
    MZN_COLONCOLON_QUOTED = 378,
    MZN_PLUSPLUS_QUOTED = 379
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{

 long long int iValue; char* sValue; bool bValue; double dValue;
         MiniZinc::Item* item;
         MiniZinc::VarDecl* vardeclexpr;
         std::vector<MiniZinc::VarDecl*>* vardeclexpr_v;
         MiniZinc::TypeInst* tiexpr;
         std::vector<MiniZinc::TypeInst*>* tiexpr_v;
         MiniZinc::Expression* expression;
         std::vector<MiniZinc::Expression*>* expression_v;
         std::vector<std::vector<MiniZinc::Expression*> >* expression_vv;
         std::vector<std::vector<std::vector<MiniZinc::Expression*> > >* expression_vvv;
         MiniZinc::Generator* generator;
         std::vector<MiniZinc::Generator>* generator_v;
         std::vector<std::string>* string_v;
         std::vector<std::pair<MiniZinc::Expression*,MiniZinc::Expression*> >* expression_p;
         MiniZinc::Generators* generators;
       


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (void *parm);

#endif /* !YY_YY_USERS_JDEKKER_REPOSITORIES_MINIZINC_LIBMZN_BUILD_MINIZINC_PARSER_TAB_HH_INCLUDED  */
