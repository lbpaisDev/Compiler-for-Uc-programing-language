#include "auxfunc.h"
#include "symbtab.h"

extern symbTab *symbTables;
extern int e3;

symbTab *auxTab;
symb *aux;

symbTab *insertTab(char *name, int isDefined)
{
    symbTab *newTab = (symbTab *)malloc(sizeof(symbTab));

    newTab->tableName = (char *)strdup(name);
    newTab->symbList = NULL;
    newTab->isDefined = isDefined;
    newTab->next = NULL;

    //If table list is null just add
    if (symbTables == NULL)
    {
        symbTables = newTab;
        return symbTables;
    }

    //Traverse list
    for (auxTab = symbTables; auxTab != NULL; auxTab = auxTab->next)
    {
        if (strcmp(auxTab->tableName, newTab->tableName) == 0)
        {
            if (DEBUG == 3)
            {
                printf("Table <%s> is already listed\n", newTab->tableName);
            }
            return NULL;
        }
        if (auxTab->next == NULL)
        {
            break;
        }
    }
    //Else just insert at the end
    auxTab->next = newTab;

    if (DEBUG == 3)
    {
        printf("Previous tab: <%s>\n", auxTab->tableName);
        printf("Inserted tab: <%s>\n", newTab->tableName);
    }

    return auxTab->next;
}

//Search for a symbol in a tab
symbTab *searchTab(char *tab)
{
    if (tab == NULL)
    {
        return NULL;
    }

    //Search table list
    for (auxTab = symbTables; auxTab != NULL; auxTab = auxTab->next)
    {
        if (strcmp(auxTab->tableName, tab) == 0)
        {
            return auxTab;
        }
        if (auxTab->next == NULL)
            break;
    }
    if (DEBUG == 3)
    {
        printf("No such table found: <%s>\n", tab);
    }
    return NULL;
}

//Insert symbol into a specific table
symb *insertSymb(char *tableName, char *name, char *type, char *tparam, int isParam)
{
    if (symbTables == NULL)
        return NULL;

    //Build new symbol
    symb *newSymb = (symb *)malloc(sizeof(symb));

    newSymb->name = (char *)strdup(name);
    newSymb->type = (char *)strdup(type);
    newSymb->tparam = (char *)strdup(tparam);
    newSymb->isParam = isParam;

    newSymb->next = NULL;

    if (DEBUG == 3)
    {
        printf("Table List: \n");
    }
    //Search table list
    for (auxTab = symbTables; auxTab != NULL; auxTab = auxTab->next)
    {
        if (DEBUG == 3)
        {
            printf("\t%s \n", auxTab->tableName);
            printf("\t%s \n", tableName);
        }
        if (strcmp(auxTab->tableName, tableName) == 0)
        {
            //If tab already has a symbol list
            if (auxTab->symbList)
            {
                //Traverse list
                for (aux = auxTab->symbList; aux != NULL; aux = aux->next)
                {
                    //Check if new symbol is already defined
                    if (strcmp(aux->name, newSymb->name) == 0)
                    {
                        //If so just print out error and return null
                        if (e3)
                            if (DEBUG == 3)
                                printf("Line %d, col %d: Symbol %s already defined\n", 0, 0, newSymb->name);
                        return aux;
                    }

                    if (aux->next == NULL)
                    {
                        break;
                    }
                }
                //Else just insert at the end
                aux->next = newSymb;
                if (DEBUG == 3)
                {
                    printf("Added symbold <%s> to table <%s>\n", newSymb->name, auxTab->tableName);
                }
                return aux->next;
            }
            //Else simply add the new symbol
            auxTab->symbList = newSymb;
            if (DEBUG == 3)
            {
                printf("Added symbold <%s> to table <%s>\n", newSymb->name, auxTab->tableName);
            }
            return auxTab->symbList;
        }
        if (auxTab->next == NULL)
            break;
    }
    if (DEBUG == 3)
    {
        printf("No such table found: <%s>\n", auxTab->tableName);
    }
    return NULL;
}

//Search for a symbol in a tab
symb *searchSymb(char *tab, char *symb)
{
    if (tab == NULL)
    {
        return NULL;
    }
    if (symb == NULL)
    {
        return NULL;
    }
    //Search table list
    for (auxTab = symbTables; auxTab != NULL; auxTab = auxTab->next)
    {
        if (strcmp(auxTab->tableName, tab) == 0)
        {
            for (aux = auxTab->symbList; aux; aux = aux->next)
                if (strcmp(aux->name, symb) == 0)
                    return aux;
            return NULL;
        }
        if (auxTab->next == NULL)
            break;
    }
    if (DEBUG == 3)
    {
        printf("No such table found: <%s>\n", tab);
    }
    return NULL;
}

//Print symbol called by printTable
void printSymb(symb *symbList)
{
    //Protection
    if (symbList == NULL)
        return;

    //Traverse list
    aux = symbList;
    while (aux != NULL)
    {
        //If is function has params
        if (strcmp(aux->tparam, "") != 0)
            printf("%s\t%s(%s)\n", aux->name, strlwr(aux->type), strlwr(aux->tparam));
        else if (aux->isParam)
            printf("%s\t%s\tparam\n", aux->name, strlwr(aux->type));
        else
            printf("%s\t%s\n", aux->name, strlwr(aux->type));

        //Exit loop
        if (aux->next == NULL)
            break;
        aux = aux->next;
    }
}

//Print table
void printTable()
{
    //Protection
    if (symbTables == NULL)
        return;

    //Traverse list
    for (auxTab = symbTables; auxTab != NULL; auxTab = auxTab->next)
    {
        //If has symbol list is function definition and needs to be printed
        if (auxTab->isDefined)
        {
            if (strcmp(auxTab->tableName, "Global") == 0)
            {
                printf("===== %s Symbol Table =====\n", auxTab->tableName);
            }
            else
            {
                printf("===== Function %s Symbol Table =====\n", auxTab->tableName);
            }
            if (auxTab->symbList != NULL)
                printSymb(auxTab->symbList);
            printf("\n");
        }
        //Else is function declaration and doesn't get printed

        if (auxTab->next == NULL)
            break;
    }
}

void setAsDefined(char *table)
{
    //Traverse list
    for (auxTab = symbTables; auxTab != NULL; auxTab = auxTab->next)
    {
        if (strcmp(auxTab->tableName, table) == 0)
        {
            auxTab->isDefined = 1;
        }
        if (auxTab->next == NULL)
        {
            break;
        }
    }
}
