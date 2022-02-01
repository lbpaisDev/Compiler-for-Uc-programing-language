%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "functions.h"
    #include "y.tab.h"

    int yylex(void);
    void yyerror(char *s);
    
    //Output control
    int l;
    int e1;
    int e2;
    int t;

    //Keep tree root to be printed in memory
    ASTNode *tree = NULL;  
%}

%union{
    char *strtok;
    struct ASTNode *ASTNode;
}


//Expected tokens
%token  CHAR ELSE
WHILE IF INT SHORT DOUBLE
RETURN VOID BITWISEAND
BITWISEOR BITWISEXOR AND 
ASSIGN MUL COMMA DIV EQ
GE GT LBRACE LE LPAR LT
MINUS MOD NE NOT OR
PLUS RBRACE RPAR SEMI RESERVED

//tokens with a lexical value strtok
%token <strtok> ID CHRLIT INTLIT REALLIT

%type <ASTNode> FunctionsAndDeclarations
FADBRACE
FunctionDefiinition
FunctionBody
DeclarationsAndStatements
FunctionDeclaration 
FunctionDeclarator
ParameterList
PLBRACE
ParameterDeclaration
Declaration
DIONBRACE
TypeSpec
Declarator
StatementWithoutError
STTMNTBRACE
Statement
Expr
XPRBRACE
COMMAExpr

//Precedence for operators in C99
%right ELSE
%right ASSIGN
%left COMMA
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE
%left GT GE
%left LT LE
%left PLUS MINUS
%left MUL DIV MOD
%left LPAR RPAR
%right NOT

%%

/*----Production 1----*/
FunctionsAndDeclarations: FunctionDefiinition FADBRACE
    {
        $$ = tree = buildNode("Program", "");
        insertChild($$, $1);
        insertChild($$, $2);
    }
    | FunctionDeclaration FADBRACE
    {
        $$ = tree = buildNode("Program", "");
        insertChild($$, $1);
        insertChild($$, $2);
    }
    | Declaration FADBRACE 
    {
        $$ = tree = buildNode("Program", "");
        insertChild($$, $1);
        insertChild($$, $2);
    }
    ;
/*Auxiliary production to handle zero or more <FunctionDefiinition|FunctionDeclaration|Declaration>*/
FADBRACE:  FunctionDefiinition FADBRACE
    {
        $$ = $1;
        insertNeighbour($$, $2);
    }
    |   FunctionDeclaration FADBRACE
    {
        $$ = $1;
        insertNeighbour($$, $2);

    }
    |  Declaration FADBRACE
    {
        $$ = $1;
        insertNeighbour($$, $2);
    }
    | 
    {
        $$ = NULL;
    }
    ;
/*----End Production----*/

/*----Production 2----*/
FunctionDefiinition: TypeSpec FunctionDeclarator FunctionBody
    {
        $$ = buildNode("FuncDefinition", "");
        insertChild($$, $1);
        insertChild($$, $2);
        insertChild($$, $3);
    }
    ;
/*----End Production----*/

/*----Production 3----*/
FunctionBody: LBRACE DeclarationsAndStatements RBRACE
    {
        $$ = buildNode("FuncBody", "");
        insertChild($$, $2);
    }
    | LBRACE RBRACE
    {
        $$ = buildNode("FuncBody", "");
    }
    ;
/*----End Production----*/

/*----Production 4----*/
DeclarationsAndStatements: StatementWithoutError DeclarationsAndStatements
    {
        $$ = $1;
        insertNeighbour($$, $2);
              
    }
    | Declaration DeclarationsAndStatements
    {
        $$ = $1;
        insertNeighbour($$, $2);
    }
    | StatementWithoutError
    {
        $$ = $1;
    }
    | Declaration
    {
        $$ = $1;
    }
    ;
/*----End Production----*/

/*----Production 5----*/
FunctionDeclaration: TypeSpec FunctionDeclarator SEMI
    {
        $$ = buildNode("FuncDeclaration", "");
        insertChild($$, $1);
        insertChild($$, $2);
    }
    ;
/*----End Production----*/

/*----Production 6----*/
FunctionDeclarator: ID LPAR ParameterList RPAR
    {
        ASTNode *Id;
        $$ = Id = buildNode("Id", $1);
        insertNeighbour($$, $3);
    }
    ;
/*----End Production----*/

/*----Production 7----*/
ParameterList: ParameterDeclaration PLBRACE
    {
        $$ = buildNode("ParamList", "");
        insertChild($$, $1);
        insertChild($$, $2);
    }
    ;
/*Auxiliary production to handle zero or more <COMMA ParameterDeclaration>*/
PLBRACE: COMMA ParameterDeclaration PLBRACE
    {
        $$ = $2;
        insertNeighbour($$, $3); 
    }
    |
    {
        $$ = NULL;
    }
    ;
/*----End Production----*/

/*----Production 8----*/
ParameterDeclaration: TypeSpec ID
    {
        $$ = buildNode("ParamDeclaration", "");
        ASTNode *Id = buildNode("Id", $2);
        insertChild($$, $1);
        insertChild($$, Id);
    }
    | TypeSpec
    {
        $$ = buildNode("ParamDeclaration", "");
        insertChild($$, $1);    
    }
    ;
/*----End Production----*/

/*----Production 9----*/
Declaration: TypeSpec Declarator DIONBRACE SEMI
    {
        $$ = buildNode("Declaration", "");
        insertChild($$, $1);
        insertChild($$, $2);
        insertNeighbour($$, $3);
        insertChilBeforeExisting($3, $1->tokenType, "");
     }
    | error SEMI 
    {
        $$ = NULL;
    }
    ;
/*Auxiliary production to handle zero or more <COMMA Declarator>*/
DIONBRACE: COMMA Declarator DIONBRACE
    {
        $$ = buildNode("Declaration", "");
        insertChild($$, $2);
        insertNeighbour($$, $3);
    }
    |
    {
        $$ = NULL;
    }
    ;
/*----End Production----*/

/*----Production 10----*/
TypeSpec: CHAR
    {
        $$ = buildNode("Char", "");
    }
    | INT 
    {
       $$ = buildNode("Int", "");
    }
    | VOID
    {
        $$ = buildNode("Void", "");
    }
    | SHORT
    {
        $$ = buildNode("Short", "");
    }
    | DOUBLE
    {
        $$ = buildNode("Double", "");
    }
    ;
/*----End Production----*/

/*----Production 11----*/
Declarator: ID ASSIGN COMMAExpr
    {
        ASTNode *Id;
        $$ = Id = buildNode("Id", $1);
        insertNeighbour($$, $3);
    }
    | ID
    {
        ASTNode *Id;
        $$ = Id = buildNode("Id", $1);
    }
    ;
/*----End Production----*/

/*----Productions 12-16----*/
StatementWithoutError: COMMAExpr SEMI
    {
        $$ = $1;
    }
    | SEMI
    {
        $$ = NULL;
    }
    | LBRACE STTMNTBRACE RBRACE 
    {
        $$ = buildNode("StatList", "");
        insertChild($$, $2);    
    }
    | IF LPAR COMMAExpr RPAR Statement ELSE Statement 
    {
        $$ = buildNode("If", "");
      if($3 == NULL){
            insertChild($$, buildNode("Null", ""));        
        }else{
            insertChild($$, $3);
        }
        if($5 == NULL){
            insertChild($$, buildNode("Null", ""));        
        }else{
            insertChild($$, $5);
        }
        if($7 == NULL){
            insertChild($$, buildNode("Null", ""));        
        }else{
            insertChild($$, $7);
        }
    }
    | IF LPAR COMMAExpr RPAR Statement %prec ELSE
    {
        $$ = buildNode("If", "");
        if($3 == NULL){
            insertChild($$, buildNode("Null", ""));        
        }else{
            insertChild($$, $3);
        }
        if($5 == NULL){
            insertChild($$, buildNode("Null", ""));        
        }else{
            insertChild($$, $5);
        }
        insertChild($$, buildNode("Null", ""));
    }
    | WHILE LPAR COMMAExpr RPAR Statement
    {
        $$ = buildNode("While", "");
        if($3 == NULL){
            insertChild($$, buildNode("Null", ""));        
        }else{
            insertChild($$, $3);
        }
        if($5 == NULL){
            insertChild($$, buildNode("Null", ""));        
        }else{
            insertChild($$, $5);
        }
    }
    | RETURN COMMAExpr SEMI
    {
        $$ = buildNode("Return", "");
        insertChild($$, $2);        
    }
    | RETURN SEMI
    {
        $$ = buildNode("Return", "");
        insertChild($$, buildNode("Null",""));
    }
    | LBRACE error RBRACE
    {
        $$ = NULL;
    }
    ;
/*Auxiliary production to handle zero or more <Statement>*/
STTMNTBRACE: Statement STTMNTBRACE
    {
        $$ = $1;
        insertNeighbour($$, $2);
    }
    | 
    {
        $$ = NULL;
    }
    ;
Statement: StatementWithoutError
    {
        $$ = $1;
    }
    | error SEMI
    {
        $$ = NULL;
    }
    ;
/*----End Production----*/

/*----Productions 17-23----*/
Expr: Expr ASSIGN Expr
    {
        $$ = buildNode("Store", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr PLUS Expr
    {
        $$ = buildNode("Add", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr MINUS Expr
    {
        $$ = buildNode("Sub", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr MUL Expr
    {
        $$ = buildNode("Mul", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr DIV Expr
    {
        $$ = buildNode("Div", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr MOD Expr
    {
        $$ = buildNode("Mod", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr OR Expr
    {
        $$ = buildNode("Or", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr AND Expr
    {        
        $$ = buildNode("And", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr BITWISEAND Expr
    {        
        $$ = buildNode("BitWiseAnd", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr BITWISEOR Expr
    {
        $$ = buildNode("BitWiseOr", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr BITWISEXOR Expr
    {
        $$ = buildNode("BitWiseXor", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr EQ Expr
    {
        $$ = buildNode("Eq", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr NE Expr
    {
        $$ = buildNode("Ne", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr LE Expr
    {
        $$ = buildNode("Le", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr GE Expr
    {
        $$ = buildNode("Ge", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr LT Expr
    {
        $$ = buildNode("Lt", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr GT Expr
    {
        $$ = buildNode("Gt", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | PLUS Expr 
    {
        $$ = buildNode("Plus", "");
        insertChild($$, $2);
    }
    | MINUS Expr 
    {
        $$ = buildNode("Minus", "");
        insertChild($$, $2);
    }
    | NOT Expr
    {
        $$ = buildNode("Not", "");
        insertChild($$, $2);
    }
    | ID LPAR Expr XPRBRACE RPAR
    {
        $$ = buildNode("Call", "");
        insertChild($$, buildNode("Id", $1));
        insertChild($$, $3);
        insertChild($$, $4);
    } 
    | ID LPAR RPAR
    {
        $$ = buildNode("Call", "");
        insertChild($$, buildNode("Id",$1));
    }
    | ID
    {
        $$ = buildNode("Id", $1);
    }
    | INTLIT
    {
        $$ = buildNode("IntLit", $1);
    }
    | CHRLIT
    {
        $$ = buildNode("ChrLit", $1);
    }
    | REALLIT
    {
        $$ = buildNode("RealLit", $1);
    }
    | LPAR COMMAExpr RPAR
    {
        $$ = $2;
    }
    | ID LPAR error RPAR
    {
        $$ = NULL;
    }
    | LPAR error RPAR
    {
        $$ = NULL;
    }   
    ;
COMMAExpr: COMMAExpr COMMA Expr
    {        
        $$ = buildNode("Comma", "");
        insertChild($$, $1);
        insertChild($$, $3);
    }
    | Expr
    {
        $$ = $1;
    }
    ;

/*Auxiliary production to handle zero or more <COMMA Expr>*/
XPRBRACE: COMMA Expr XPRBRACE
    {
        $$ = $2;
        insertNeighbour($$, $3);
    }
    | 
    {
        $$ = NULL;
    }
    ;
/*----End Production----*/

%%

int main(int argc, char *argv[]){
    if(argc >= 2){
        if(strcmp(argv[1], "-l") == 0){
            l  = 1;
            e1 = 1;
            t  = 0;
            e2 = 0;
            yylex();
        }else if(strcmp(argv[1], "-e1") == 0){
            l = 0;
            e1 = 1;
            t  = 0;
            e2 = 0;
            yylex();
        }else if(strcmp(argv[1], "-t") == 0){
            l  = 0;
            e1 = 1;
            t  = 1;
            e2 = 1;
            yyparse();
            if(syntaxErrors == 0){
                printAST(tree);
                freeAST(tree);
            }
            syntaxErrors = 0;
        }else if(strcmp(argv[1], "-e2") == 0){
            t  = 0;
            l  = 0;
            e1 = 1;
            e2 = 1;
            yyparse();
            freeAST(tree);
        }
    }else{
        l  = 0;
        t  = 0;
        e1 = 1;
        e2 = 1;
        yyparse();
        freeAST(tree);
        return 0;      
    }
}
