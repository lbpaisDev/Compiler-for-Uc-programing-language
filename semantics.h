#include "auxfunc.h"

//Semantics check functions
int checkFuncDef(ASTNode *node);
int checkFuncDecl(ASTNode *node);
int checkFuncBody(ASTNode *node, char *table);
int checkDecl(ASTNode *node, char *table);
int checkTree(ASTNode *root);
int checkExpr(ASTNode *node, char *table);
int semanticError(int error, ASTNode *node, char *errorInfo, int nline, int ncol);
int checkReturn(ASTNode *node, char *table);
int checkIf(ASTNode *node, char *table);
int checkStatList(ASTNode *node, char *table);
int checkDeclAndSttmnt(ASTNode *aux, char *table);
int checkWhile(ASTNode *node, char *table);
char *getNote(ASTNode *aux, char *table);
void makeAnotation(ASTNode *node, char *table);
void setNote(ASTNode *node, char *table);
int isRealType(char *note);
int isArithmeticType(char *note);
