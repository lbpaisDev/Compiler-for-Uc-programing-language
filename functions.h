#ifndef AUXSTRUCTURES_H
#define AUXSTRUCTURES_H
#define DEBUG 0

typedef struct ASTNode
{
    /* Node data*/
    //Token type are the ones explicit such as Program and others
    char *tokenType;
    //Tokens such as ID can have a lexical value
    //ASTNode needs to be able to store it
    char *tokenLval;

    /* Node structs to build the tree*/
    //Children (one level deeper)
    struct ASTNode *child;
    //Neighbour (same level)
    //Linked list
    struct ASTNode *next;

} ASTNode;

int syntaxErrors;

ASTNode *buildNode(char *tokenType, char *tokenLval);
void insertChild(ASTNode *parent, ASTNode *child);
void insertNeighbour(ASTNode *parent, ASTNode *neighbour);
void printAST(ASTNode *node);
void freeAST(ASTNode *root);
void saveNode(ASTNode *node);
void insertChilBeforeExisting(ASTNode *parent, char *tokenType, char *tokenLval);

#endif