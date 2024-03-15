%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

#define yylval cool_yylval
#define yylex  cool_yylex

#define MAX_STR_CONST 1025
#define YY_NO_UNPUT

extern FILE *fin;

#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST];
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;
unsigned int comment_lvl = 0;

%}

%x MULTI_COMMENT
%x SINGLE_COMMENT
%x STRING
%x STRING_ERROR

%%
"--"						{ BEGIN(SINGLE_COMMENT); }
<SINGLE_COMMENT>.			{ }
<SINGLE_COMMENT>\n			{ BEGIN(INITIAL); curr_lineno++; }
<SINGLE_COMMENT><<EOF>>		{ BEGIN(INITIAL); }

"(*"						{ BEGIN(MULTI_COMMENT); comment_lvl++; }
<MULTI_COMMENT>.			{ }
<MULTI_COMMENT>\n			{ curr_lineno++; }
<MULTI_COMMENT><<EOF>>		{ cool_yylval.error_msg = "EOF in comment" ; BEGIN(INITIAL); return (ERROR);  }
<MULTI_COMMENT>"(*"			{ comment_lvl++; }
<MULTI_COMMENT>"*)"			{ comment_lvl--; if(comment_lvl == 0) { BEGIN(INITIAL); } }

"\""						{ BEGIN(STRING); string_buf_ptr = string_buf; }
<STRING>\n					{ cool_yylval.error_msg = "Unterminated string constant"; BEGIN(INITIAL); return (ERROR);}
<STRING>\\n					{ *string_buf_ptr++ = '\n'; 	if(string_buf_ptr - string_buf >= MAX_STR_CONST) { cool_yylval.error_msg = "String constant too long"; BEGIN(STRING_ERROR); return (ERROR); }}
<STRING>\\t					{ *string_buf_ptr++ = '\t'; 	if(string_buf_ptr - string_buf >= MAX_STR_CONST) { cool_yylval.error_msg = "String constant too long"; BEGIN(STRING_ERROR); return (ERROR); }}
<STRING>\\b					{ *string_buf_ptr++ = '\b'; 	if(string_buf_ptr - string_buf >= MAX_STR_CONST) { cool_yylval.error_msg = "String constant too long"; BEGIN(STRING_ERROR); return (ERROR); }}
<STRING>\\f					{ *string_buf_ptr++ = '\f'; 	if(string_buf_ptr - string_buf >= MAX_STR_CONST) { cool_yylval.error_msg = "String constant too long"; BEGIN(STRING_ERROR); return (ERROR); }}
<STRING>\\\"				{ *string_buf_ptr++ = '\"';		if(string_buf_ptr - string_buf >= MAX_STR_CONST) { cool_yylval.error_msg = "String constant too long"; BEGIN(STRING_ERROR); return (ERROR); }}
<STRING>\\[^\0]				{ *string_buf_ptr++ = yytext[1];if(string_buf_ptr - string_buf >= MAX_STR_CONST) { cool_yylval.error_msg = "String constant too long"; BEGIN(STRING_ERROR); return (ERROR); }}
<STRING>[^\"\n\0]			{ *string_buf_ptr++ = yytext[0];if(string_buf_ptr - string_buf >= MAX_STR_CONST) { cool_yylval.error_msg = "String constant too long"; BEGIN(STRING_ERROR); return (ERROR); }}
<STRING>\"					{ BEGIN(INITIAL); *string_buf_ptr = '\0'; cool_yylval.symbol = stringtable.add_string(string_buf); return (STR_CONST); }
<STRING>.					{ cool_yylval.error_msg = "String contains null character" ; BEGIN(STRING_ERROR); return (ERROR); }
<STRING><<EOF>>				{ cool_yylval.error_msg = "EOF in string constant" ; BEGIN(INITIAL); return (ERROR); }

<STRING_ERROR>[^\"]*[\"\n]	{ BEGIN(INITIAL); }


"\n"						{ curr_lineno++;}
[ \t\b\f\v\r]+				{ }
"\*\)"						{ cool_yylval.error_msg = "Unmatched *)" ; return (ERROR); }

"=>"						{ return (DARROW); }
"<-"						{ return (ASSIGN); }
"<="						{ return (LE); }
"\."						{ return ('.'); }
"@"							{ return ('@'); }
"~"							{ return ('~'); }
"\+"						{ return ('+'); }
"-"							{ return ('-'); }
"\*"						{ return ('*'); }
"/"							{ return ('/'); }
"<"							{ return ('<'); }
"="							{ return ('='); }
";"							{ return (';'); }
":"							{ return (':'); }
","							{ return (','); }
"\("						{ return ('('); }
"\)"						{ return (')'); }
"\{"						{ return ('{'); }
"\}"						{ return ('}'); }

(?i:class)					{ return (CLASS); }
(?i:else)					{ return (ELSE); }
(?i:fi)						{ return (FI); }
(?i:if)						{ return (IF); }
(?i:in)						{ return (IN); }
(?i:inherits)				{ return (INHERITS); }
(?i:isvoid)					{ return (ISVOID); }
(?i:let)					{ return (LET); }
(?i:loop)					{ return (LOOP); }
(?i:pool)					{ return (POOL); }
(?i:then)					{ return (THEN); }
(?i:while)					{ return (WHILE); }
(?i:case)					{ return (CASE); }
(?i:esac)					{ return (ESAC); }
(?i:new)					{ return (NEW); }
(?i:of)						{ return (OF); }
(?i:not)					{ return (NOT); }

"t"(?i:rue)					{ cool_yylval.boolean = true; return (BOOL_CONST); }
"f"(?i:alse)				{ cool_yylval.boolean = false; return (BOOL_CONST); }
[0-9]+						{ cool_yylval.symbol = stringtable.add_string(yytext); return (INT_CONST); }
[A-Z][A-Za-z0-9_]*			{ cool_yylval.symbol = stringtable.add_string(yytext); return (TYPEID); }
[a-z][A-Za-z0-9_]*			{ cool_yylval.symbol = stringtable.add_string(yytext); return (OBJECTID); }

.							{ cool_yylval.error_msg = yytext ; return (ERROR); }

%%