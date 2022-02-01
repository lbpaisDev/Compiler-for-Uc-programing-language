#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void printDebugNode(ASTNode *node)
{
    printf("%s", node->tokenType);
    //Tokens with lexical value are printed between par
    if (strcmp(node->tokenLval, "") != 0)
    {
        printf("(%s)", node->tokenLval);
    }
}

ASTNode *buildNode(char *tokenType, char *tokenLval)
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
    newNode->next = NULL;

    if (DEBUG)
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

    if (DEBUG)
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

    if (DEBUG)
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
        if (DEBUG)
            printf("<Error> Node supplied to printASTRecursive is NULL!\n");
        return;
    }

    //Pretty print
    int depthcpy = depth;
    while (depthcpy--)
    {
        printf("..");
    }
    printf("%s", node->tokenType);
    //Tokens with lexical value are printed between par
    if (strcmp(node->tokenLval, "") != 0)
    {
        printf("(%s)", node->tokenLval);
    }
    printf("\n");

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
        if (DEBUG)
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
        if (DEBUG)
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

// Function to add a younger child (before existing child in list)
// Protected
void insertChilBeforeExisting(ASTNode *parent, char *tokenType, char *tokenLval)
{
    if (parent == NULL)
    {
        return;
    }
    while (parent->next)
    {
        ASTNode *temp = parent->child;
        parent->child = buildNode(tokenType, tokenLval);
        parent->child->next = temp;
        parent = parent->next;
    }

    ASTNode *temp = parent->child;
    parent->child = buildNode(tokenType, tokenLval);
    parent->child->next = temp;
}