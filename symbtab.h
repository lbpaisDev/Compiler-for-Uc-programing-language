#ifndef symbTab_H
#define symbTab_H
#include "auxfunc.h"

//Symbol struct
typedef struct _symb
{
    char *name;
    char *type;
    char *tparam;
    int isParam;
    struct _symb *next;
} symb;

//Table struct
typedef struct _symbTab
{
    char *tableName;
    int isDefined;
    symb *symbList;
    struct _symbTab *next;
} symbTab;

//Table functions adapted from PL5
symbTab *insertTab(char *name, int isDefined);
symb *insertSymb(char *tableName, char *name, char *type, char *tparam, int isParam);
symb *searchSymb(char *tab, char *symb);
void printTable();
void printSymb(symb *symbList);
void setAsDefined(char *table);
symbTab *searchTab(char *tab);

#endif
