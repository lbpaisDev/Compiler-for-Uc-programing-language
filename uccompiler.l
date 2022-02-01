    /* Authors:
            @Leandro Pais 2017251509
    */

/* C Code */
%{
    #include <stdio.h>
    #include <stdlib.h>
    
    //Output control
    int errorOnly = 0;
 
    //Compute lines and columns
    int nline = 1;
    int ncol = 1;
    int colSave, lineSave;

%}

/* Keywords and reserved identifiers by C99 standards */
/* Simple tokens */
CHAR                char
ELSE                else 
WHILE               while
IF                  if 
INT                 int
SHORT               short
DOUBLE              double 
RETURN              return
VOID                void 
BITWISEAND          "&"
BITWISEOR           "|"
BITWISEXOR          "^"
AND                 "&&"
ASSIGN              "="
MUL                 "*"
COMMA               ","
DIV                 "/"
EQ                  "=="
GE                  ">="
GT                  ">"
LBRACE              "{"
LE                  "<="
LPAR                "("
LT                  "<"
MINUS               "-"
MOD                 "%"
NE                  "!="
NOT                 "!"
OR                  "||"
PLUS                "+"
RBRACE              "}"
RPAR                ")"
SEMI                ";"


/* Reserved words used in C99 but not in UC compiler */
RESERVED            ("["|"]"|"++"|"--"|auto|break|case|const|continue|default|do|enum|extern|float|for|goto|inline|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|_Bool|_Complex|_Imaginary)

/* Complex tokens */
/* Generic */
spc                 (" "|\t)
nln                 (\n|\r|(\r\n))
/* Id */
ID                  ([a-zA-Z]|"_")([a-zA-Z]|[0-9]|"_")*
/* Int */
INTLIT              [0-9]+
/* Real */
exp                 (e|E)("+"|"-")?{INTLIT}+
REALLIT             ({INTLIT}"."{INTLIT}?{exp}?|"."({INTLIT}{exp}|{INTLIT})|{INTLIT}{exp})
/* Char */
char                [^'\\\n\r]
scp                 (\\n|\\t|\\\\|\\\'|\\\"|\\[0-7]{1,3})
CHRLIT              '({char}|{scp})'
UNTRCHRCNST         '({char}|{scp}|\\.)*(\\\n)?
INVCHRCNST          '({char}|{scp}|\\.)*'

/* Comments */
SNGLLNCMMT           "//".*
%X MLTLNCMMNT



%%
{RESERVED}          {if(errorOnly == 0)printf("RESERVED(%s)\n",yytext);ncol += yyleng;}

{CHAR}              {if(errorOnly == 0)printf("CHAR\n");ncol += yyleng;}
{ELSE}              {if(errorOnly == 0)printf("ELSE\n");ncol += yyleng;}
{WHILE}             {if(errorOnly == 0)printf("WHILE\n");ncol += yyleng;}
{IF}                {if(errorOnly == 0)printf("IF\n");ncol += yyleng;}
{INT}               {if(errorOnly == 0)printf("INT\n");ncol += yyleng;}
{SHORT}             {if(errorOnly == 0)printf("SHORT\n");ncol += yyleng;}
{DOUBLE}            {if(errorOnly == 0)printf("DOUBLE\n");ncol += yyleng;}
{RETURN}            {if(errorOnly == 0)printf("RETURN\n");ncol += yyleng;}
{VOID}              {if(errorOnly == 0)printf("VOID\n");ncol += yyleng;}
{BITWISEAND}        {if(errorOnly == 0)printf("BITWISEAND\n");ncol += yyleng;}
{BITWISEOR}         {if(errorOnly == 0)printf("BITWISEOR\n");ncol += yyleng;}
{BITWISEXOR}        {if(errorOnly == 0)printf("BITWISEXOR\n");ncol += yyleng;}
{AND}               {if(errorOnly == 0)printf("AND\n");ncol += yyleng;}
{ASSIGN}            {if(errorOnly == 0)printf("ASSIGN\n");ncol += yyleng;}
{MUL}               {if(errorOnly == 0)printf("MUL\n");ncol += yyleng;}
{COMMA}             {if(errorOnly == 0)printf("COMMA\n");ncol += yyleng;}
{DIV}               {if(errorOnly == 0)printf("DIV\n");ncol += yyleng;}
{EQ}                {if(errorOnly == 0)printf("EQ\n");ncol += yyleng;}
{GE}                {if(errorOnly == 0)printf("GE\n");ncol += yyleng;}
{GT}                {if(errorOnly == 0)printf("GT\n");ncol += yyleng;}
{LBRACE}            {if(errorOnly == 0)printf("LBRACE\n");ncol += yyleng;}
{LE}                {if(errorOnly == 0)printf("LE\n");ncol += yyleng;}
{LPAR}              {if(errorOnly == 0)printf("LPAR\n");ncol += yyleng;}
{LT}                {if(errorOnly == 0)printf("LT\n");ncol += yyleng;}
{MINUS}             {if(errorOnly == 0)printf("MINUS\n");ncol += yyleng;}
{MOD}               {if(errorOnly == 0)printf("MOD\n");ncol += yyleng;}
{NE}                {if(errorOnly == 0)printf("NE\n");ncol += yyleng;}
{NOT}               {if(errorOnly == 0)printf("NOT\n");ncol += yyleng;}
{OR}                {if(errorOnly == 0)printf("OR\n");ncol += yyleng;}
{PLUS}              {if(errorOnly == 0)printf("PLUS\n");ncol += yyleng;}
{RBRACE}            {if(errorOnly == 0)printf("RBRACE\n");ncol += yyleng;}
{RPAR}              {if(errorOnly == 0)printf("RPAR\n");ncol += yyleng;}
{SEMI}              {if(errorOnly == 0)printf("SEMI\n");ncol += yyleng;}

{ID}                {if(errorOnly == 0)printf("ID(%s)\n", yytext);ncol += yyleng;}      
{CHRLIT}            {if(errorOnly == 0)printf("CHRLIT(%s)\n", yytext);ncol += yyleng;}
{INTLIT}            {if(errorOnly == 0)printf("INTLIT(%s)\n", yytext);ncol += yyleng;}
{REALLIT}           {if(errorOnly == 0)printf("REALLIT(%s)\n", yytext);ncol += yyleng;}

{SNGLLNCMMT}        {ncol += yyleng;}

"/*"                {BEGIN MLTLNCMMNT; colSave = ncol; lineSave = nline; ncol += yyleng;}  
<MLTLNCMMNT>.       {ncol += yyleng;}
<MLTLNCMMNT>{nln}   {nline++;ncol = 1;}
<MLTLNCMMNT><<EOF>> {printf("Line %d, col %d: unterminated comment\n", lineSave, colSave);ncol = 1;BEGIN 0;return 0;}
<MLTLNCMMNT>"*/"    {BEGIN 0;ncol += yyleng;}

{INVCHRCNST}        {printf("Line %d, col %d: invalid char constant (%s)\n", nline, ncol, yytext);ncol += yyleng;}
{UNTRCHRCNST}       {printf("Line %d, col %d: unterminated char constant\n", nline, ncol);if(strchr(yytext,'\n') == NULL){ncol += yyleng;}else{ncol = 1; nline++;}}

{nln}               {nline++;ncol = 1;}
{spc}               {ncol++;}

.                   {printf("Line %d, col %d: illegal character (%s)\n", nline, ncol, yytext); ncol += yyleng;}

%%
int main(int argc, char *argv[]){
    //Handle input from CLI
    if(argc >= 2){
        if(strcmp(argv[1], "-l") == 0){
            errorOnly = 0;
            yylex();
            return 0;
        }else if(strcmp(argv[1], "-e1") == 0){
            errorOnly = 1;
            yylex();
            return 0;
        }
    //No args
    }else{
        errorOnly = 1;
        yylex();
        return 0;      
    }
}

int yywrap(){
    return 1;
}
