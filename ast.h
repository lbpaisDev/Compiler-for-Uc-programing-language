#ifndef AST_H
#define AST_H

#include "auxfunc.h"

typedef struct tok
{
    char *strtok;
    int nline;
    int ncol;
} tok;

typedef struct ASTNode
{
    /* Node data*/
    //Token type are the ones explicit such as Program and others
    char *tokenType;
    //Tokens such as ID can have a lexical value
    //ASTNode needs to be able to store it
    char *tokenLval;
    char *note;
    int isExpression;
    int isOp;
    int line;
    int col;
    /* Node structs to build the tree*/
    //Children (one level deeper)
    struct ASTNode *child;
    //Neighbour (same level)
    //Linked list
    struct ASTNode *next;

} ASTNode;

ASTNode *buildNode(char *tokenType, char *tokenLval, int isExpression, int isOp, int line, int col);
void insertChild(ASTNode *parent, ASTNode *child);
void insertNeighbour(ASTNode *parent, ASTNode *neighbour);
void printAST(ASTNode *node);
void freeAST(ASTNode *root);
void saveNode(ASTNode *node);
void insertChilBeforeExisting(ASTNode *parent, char *tokenType, char *tokenLval, int isExpression, int isOp, int line, int col);
int countChildren(ASTNode *parent);
void anotateNode(ASTNode *node, ASTNode *root, char *note);
tok *buildTok(char *strtok, int nline, int ncol);

#endif