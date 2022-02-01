#include "auxfunc.h"

extern ASTNode *tree;
extern int s;

void printDebugNode(ASTNode *node)
{
    printf("%s", node->tokenType);
    //Tokens with lexical value are printed between par
    if (strcmp(node->tokenLval, "") != 0)
    {
        printf("(%s)", node->tokenLval);
    }
}

tok *buildTok(char *strtok, int nline, int ncol)
{
    tok *newTok = (tok *)malloc(sizeof(tok));

    newTok->strtok = (char *)strdup(strtok);
    newTok->nline = nline;
    newTok->ncol = ncol;

    return newTok;
}

ASTNode *buildNode(char *tokenType, char *tokenLval, int isExpression, int isOp, int line, int col)
{
    ASTNode *newNode = (ASTNode *)malloc(sizeof(ASTNode));

    if (tokenType != NULL)
        newNode->tokenType = (char *)strdup(tokenType);
    else
        newNode->tokenType = NULL;

    if (tokenType != NULL)
        newNode->tokenLval = (char *)strdup(tokenLval);
    else
        newNode->tokenLval = NULL;

    newNode->child = NULL;
    newNode->note = "";
    newNode->isExpression = isExpression;
    newNode->isOp = isOp;
    newNode->line = line;
    newNode->col = col;
    newNode->next = NULL;

    if (DEBUG == 1)
    {
        printf("--- BUILT ---");
        printDebugNode(newNode);
        printf("\n");
    }

    return newNode;
}

//Insert a node deeper than the previous node
void insertChild(ASTNode *parent, ASTNode *child)
{
    //Safeguard checks
    if (parent == NULL)
    {
        return;
    }
    if (child == NULL)
    {
        return;
    }

    //If parent has child
    if (parent->child != NULL)
    {
        //Insert at the end of child's linked list
        ASTNode *treePtr;
        for (treePtr = parent->child; treePtr->next != NULL; treePtr = treePtr->next)
            ;
        treePtr->next = child;
        return;
    }

    //Else parent has no child just add
    parent->child = child;

    if (DEBUG == 1)
    {
        printf("--- ADDED CHILD ");
        printDebugNode(child);
        printf(" TO ");
        printDebugNode(parent);
        printf("---\n");
    }
}

//Insert a node at the same level than the previous node
void insertNeighbour(ASTNode *parent, ASTNode *neighbour)
{
    if (parent == NULL)
    {
        return;
    }
    if (neighbour == NULL)
    {
        return;
    }

    //Traverse trough the pre-existing linked list and add at the end
    ASTNode *treePtr;
    for (treePtr = parent; treePtr->next != NULL; treePtr = treePtr->next)
        ;
    treePtr->next = neighbour;

    if (DEBUG == 1)
    {
        printf("--- ADDED NEIGHBOUR ");
        printDebugNode(neighbour);
        printf(" TO ");
        printDebugNode(parent);
        printf("---\n");
    }
}

//Recursive step (receives depth)
void printASTRec(ASTNode *node, int depth)
{

    if (node == NULL)
    {
        if (DEBUG == 1)
            printf("<Error> Node supplied to printASTRecursive is NULL!\n");
        return;
    }
    if (strcmp(node->tokenType, "Empty") != 0)
    { //Pretty print
        int depthcpy = depth;
        while (depthcpy--)
        {
            printf("..");
        }
        printf("%s", cap(node->tokenType));
        //Tokens with lexical value are printed between par
        if (strcmp(node->tokenLval, "") != 0)
        {
            printf("(%s)", node->tokenLval);
        }
        if (s)
        {
            //Print tree node from semantic
            if (node->isExpression)
            {
                printf(" - %s", node->note);
            }
        }

        printf("\n");
    }

    //Call recursive step for children and neighbours
    if (node->child != NULL)
        //Increase depth level
        printASTRec(node->child, depth + 1);
    if (node->next != NULL)
        //Same depth levl
        printASTRec(node->next, depth);
}

//Pretty print AST
void printAST(ASTNode *root)
{
    if (root == NULL)
    {
        if (DEBUG == 1)
            printf("<Error> Node supplied to printAST is NULL!\n");
        return;
    }
    //Always program
    printf("%s\n", root->tokenType);
    //Recursive step with increased depth
    printASTRec(root->child, 1);
}

//Free memory allocated previously
void freeAST(ASTNode *root)
{
    if (root == NULL)
    {
        if (DEBUG == 1)
            printf("<Error> Node supplied to freeAST is NULL!\n");
        return;
    }

    if (root->child != NULL)
        freeAST(root->child);
    if (root->next != NULL)
        freeAST(root->next);

    free((char *)root->tokenType);
    free((char *)root->tokenLval);

    root->child = NULL;
    root->next = NULL;

    free(root);
}

// Function to add a younger child
void insertChilBeforeExisting(ASTNode *parent, char *tokenType, char *tokenLval, int isExpression, int isOp, int line, int col)
{
    if (parent == NULL)
    {
        return;
    }
    while (parent->next)
    {
        ASTNode *temp = parent->child;
        parent->child = buildNode(tokenType, tokenLval, isExpression, isOp, line, col);
        parent->child->next = temp;
        parent = parent->next;
    }

    ASTNode *temp = parent->child;
    parent->child = buildNode(tokenType, tokenLval, isExpression, isOp, line, col);
    parent->child->next = temp;
}

int countChildren(ASTNode *parent)
{
    if (parent == NULL)
        return -1;
    int childrenCounter = 0;
    if (parent->child != NULL)
    {
        childrenCounter++;
        if (parent->child->next != NULL)
            for (ASTNode *aux = parent->child->next; aux->next != NULL; aux = aux->next)
            {
                childrenCounter++;
            }
    }
    return childrenCounter;
}

void anotateNode(ASTNode *node, ASTNode *root, char *note)
{
    if (node == NULL)
        return;

    if (root == NULL)
        return;

    char *lwrnote = (char *)strlwr(note);

    if (node == root)
    {
        if (strcmp(node->tokenLval, "") != 0)
        {
            if (strcmp(node->tokenLval, root->tokenLval) == 0)
                root->note = (char *)strdup(lwrnote);
        }
        else
        {
            root->note = (char *)strdup(lwrnote);
        }
    }

    anotateNode(node, root->child, note);
    anotateNode(node, root->next, note);
}