#include "auxfunc.h"

extern symbTab *symbTables;
extern ASTNode *tree;
extern int e3;

void setNote(ASTNode *node, char *table)
{
    if (node == NULL || node->child == NULL || node->child->next == NULL)
        return;

    if (strcmp(strlwr(node->child->note), "char") == 0 && strcmp(strlwr(node->child->next->note), "char") == 0)
    {
        anotateNode(node, tree, "char");
    }
    if (strcmp(strlwr(node->child->note), "char") == 0 && strcmp(strlwr(node->child->next->note), "short") == 0)
    {
        anotateNode(node, tree, "short");
    }
    if (strcmp(strlwr(node->child->note), "char") == 0 && strcmp(strlwr(node->child->next->note), "int") == 0)
    {
        anotateNode(node, tree, "int");
    }
    if (strcmp(strlwr(node->child->note), "char") == 0 && strcmp(strlwr(node->child->next->note), "double") == 0)
    {
        anotateNode(node, tree, "double");
    }
    if (strcmp(strlwr(node->child->note), "short") == 0 && strcmp(strlwr(node->child->next->note), "char") == 0)
    {
        anotateNode(node, tree, "short");
    }
    if (strcmp(strlwr(node->child->note), "short") == 0 && strcmp(strlwr(node->child->next->note), "short") == 0)
    {
        anotateNode(node, tree, "short");
    }
    if (strcmp(strlwr(node->child->note), "short") == 0 && strcmp(strlwr(node->child->next->note), "int") == 0)
    {
        anotateNode(node, tree, "int");
    }
    if (strcmp(strlwr(node->child->note), "short") == 0 && strcmp(strlwr(node->child->next->note), "double") == 0)
    {
        anotateNode(node, tree, "double");
    }
    if (strcmp(strlwr(node->child->note), "int") == 0 && strcmp(strlwr(node->child->next->note), "char") == 0)
    {
        anotateNode(node, tree, "int");
    }
    if (strcmp(strlwr(node->child->note), "int") == 0 && strcmp(strlwr(node->child->next->note), "short") == 0)
    {
        anotateNode(node, tree, "int");
    }
    if (strcmp(strlwr(node->child->note), "int") == 0 && strcmp(strlwr(node->child->next->note), "int") == 0)
    {
        anotateNode(node, tree, "int");
    }
    if (strcmp(strlwr(node->child->note), "int") == 0 && strcmp(strlwr(node->child->next->note), "double") == 0)
    {
        anotateNode(node, tree, "double");
    }
    if (strcmp(strlwr(node->child->note), "double") == 0 && strcmp(strlwr(node->child->next->note), "char") == 0)
    {
        anotateNode(node, tree, "double");
    }
    if (strcmp(strlwr(node->child->note), "double") == 0 && strcmp(strlwr(node->child->next->note), "short") == 0)
    {
        anotateNode(node, tree, "double");
    }
    if (strcmp(strlwr(node->child->note), "double") == 0 && strcmp(strlwr(node->child->next->note), "int") == 0)
    {
        anotateNode(node, tree, "double");
    }
    if (strcmp(strlwr(node->child->note), "double") == 0 && strcmp(strlwr(node->child->next->note), "double") == 0)
    {
        anotateNode(node, tree, "double");
    }

    if (strcmp(strlwr(node->child->note), "undef") == 0 && strcmp(strlwr(node->child->next->note), "char") == 0)
    {
        anotateNode(node, tree, "char");
    }
    if (strcmp(strlwr(node->child->note), "undef") == 0 && strcmp(strlwr(node->child->next->note), "short") == 0)
    {
        anotateNode(node, tree, "short");
    }
    if (strcmp(strlwr(node->child->note), "undef") == 0 && strcmp(strlwr(node->child->next->note), "int") == 0)
    {
        anotateNode(node, tree, "int");
    }
    if (strcmp(strlwr(node->child->note), "undef") == 0 && strcmp(strlwr(node->child->next->note), "double") == 0)
    {
        anotateNode(node, tree, "double");
    }
    if (strcmp(strlwr(node->child->note), "char") == 0 && strcmp(strlwr(node->child->next->note), "undef") == 0)
    {
        anotateNode(node, tree, "char");
    }
    if (strcmp(strlwr(node->child->note), "short") == 0 && strcmp(strlwr(node->child->next->note), "undef") == 0)
    {
        anotateNode(node, tree, "short");
    }
    if (strcmp(strlwr(node->child->note), "int") == 0 && strcmp(strlwr(node->child->next->note), "undef") == 0)
    {
        anotateNode(node, tree, "int");
    }
    if (strcmp(strlwr(node->child->note), "undef") == 0 && strcmp(strlwr(node->child->next->note), "undef") == 0)
    {
        anotateNode(node, tree, "undef");
    }

    if (strcmp(strlwr(node->child->note), "void") == 0 && strcmp(strlwr(node->child->next->note), "char") == 0)
    {
        anotateNode(node, tree, "undef");
    }
    if (strcmp(strlwr(node->child->note), "void") == 0 && strcmp(strlwr(node->child->next->note), "short") == 0)
    {
        anotateNode(node, tree, "undef");
    }
    if (strcmp(strlwr(node->child->note), "void") == 0 && strcmp(strlwr(node->child->next->note), "int") == 0)
    {
        anotateNode(node, tree, "undef");
    }
    if (strcmp(strlwr(node->child->note), "void") == 0 && strcmp(strlwr(node->child->next->note), "double") == 0)
    {
        anotateNode(node, tree, "undef");
    }
    if (strcmp(strlwr(node->child->note), "char") == 0 && strcmp(strlwr(node->child->next->note), "void") == 0)
    {
        anotateNode(node, tree, "undef");
    }
    if (strcmp(strlwr(node->child->note), "short") == 0 && strcmp(strlwr(node->child->next->note), "void") == 0)
    {
        anotateNode(node, tree, "undef");
    }
    if (strcmp(strlwr(node->child->note), "int") == 0 && strcmp(strlwr(node->child->next->note), "void") == 0)
    {
        anotateNode(node, tree, "undef");
    }
    if (strcmp(strlwr(node->child->note), "undef") == 0 && strcmp(strlwr(node->child->next->note), "void") == 0)
    {
        anotateNode(node, tree, "undef");
    }
}

void makeAnotation(ASTNode *node, char *table)
{
    if (node->child != NULL)
    {
        symb *auxSymb = searchSymb(table, node->child->tokenLval);
        if (auxSymb == NULL)
        {
            auxSymb = searchSymb("Global", node->child->tokenLval);
            if (auxSymb == NULL)
            {
                if (strcmp(node->child->tokenType, "IntLit") == 0)
                {
                    anotateNode(node, tree, "int");
                }

                else if (strcmp(node->child->tokenType, "RealLit") == 0)
                {
                    anotateNode(node, tree, "double");
                }

                else if (strcmp(node->child->tokenType, "ChrLit") == 0)
                {
                    anotateNode(node, tree, "char");
                }
                else
                {
                    anotateNode(node, tree, "undef");
                }

                anotateNode(node->child, tree, "undef");
            }
            else
            {
                anotateNode(node, tree, auxSymb->type);
            }
        }
        else
        {
            anotateNode(node, tree, auxSymb->type);
        }
    }
}

char *getNote(ASTNode *aux, char *table)
{
    symb *auxSymb;
    int priority[255];
    int sizecounter = 0;

    while (aux != NULL)
    {
        auxSymb = searchSymb(table, aux->tokenLval);
        if (auxSymb == NULL)
        {
            auxSymb = searchSymb("Global", aux->tokenLval);
            if (auxSymb == NULL)
            {
                anotateNode(aux, tree, "undef");
            }
            else
            {
                if (strcmp(auxSymb->type, "Char") == 0)
                {
                    priority[sizecounter] = 0;
                    sizecounter++;
                }

                if (strcmp(auxSymb->type, "Short") == 0)
                {
                    priority[sizecounter] = 1;
                    sizecounter++;
                }

                if (strcmp(auxSymb->type, "Int") == 0)
                {
                    priority[sizecounter] = 2;
                    sizecounter++;
                }

                if (strcmp(auxSymb->type, "Double") == 0)
                {
                    priority[sizecounter] = 3;
                    sizecounter++;
                }
            }
        }
        else
        {
            if (strcmp(auxSymb->type, "Char") == 0)
            {
                priority[sizecounter] = 0;
                sizecounter++;
            }

            if (strcmp(auxSymb->type, "Short") == 0)
            {
                priority[sizecounter] = 1;
                sizecounter++;
            }

            if (strcmp(auxSymb->type, "Int") == 0)
            {
                priority[sizecounter] = 2;
                sizecounter++;
            }

            if (strcmp(auxSymb->type, "Double") == 0)
            {
                priority[sizecounter] = 3;
                sizecounter++;
            }
        }

        if (aux->isExpression)
        {
            if (strcmp(aux->tokenType, "ChrLit") == 0)
            {
                priority[sizecounter] = 0;
                sizecounter++;
            }

            if (strcmp(aux->tokenType, "IntLit") == 0)
            {
                priority[sizecounter] = 2;
                sizecounter++;
            }

            if (strcmp(aux->tokenType, "RealLit") == 0)
            {
                priority[sizecounter] = 3;
                sizecounter++;
            }
            checkExpr(aux, table);
        }
        if (aux->next == NULL)
            break;
        aux = aux->next;
    }

    //Return correct type
    int max = getMax(priority, sizecounter);
    if (max == 0)
    {
        return "char";
    }
    else if (max == 1)
    {
        return "short";
    }
    else if (max == 2)
    {
        return "int";
    }
    return "double";
}

int checkDeclAndSttmnt(ASTNode *aux, char *table)
{
    int errors = 0;
    while (aux != NULL)
    {
        //Check which type it is
        //Call func accordingly (not very efficient)
        if (strcmp(aux->tokenType, "Declaration") == 0)
        {
            errors += checkDecl(aux, table);
        }

        if (strcmp(aux->tokenType, "StatList") == 0)
        {
            errors += checkStatList(aux, table);
        }

        if (strcmp(aux->tokenType, "While") == 0)
        {
            errors += checkWhile(aux, table);
        }

        if (strcmp(aux->tokenType, "If") == 0)
        {
            errors += checkIf(aux, table);
        }

        if (strcmp(aux->tokenType, "Return") == 0)
        {
            errors += checkReturn(aux, table);
        }

        if (aux->isExpression)
        {
            errors += checkExpr(aux, table);
        }

        //Next child
        if (aux->next == NULL)
            break;
        aux = aux->next;
    }
    return errors;
}

int checkWhile(ASTNode *node, char *table)
{
    int errors = 0;

    //Memory protection
    if (node->child != NULL)
    {
        //Call statement check
        ASTNode *aux = node->child;
        errors += checkDeclAndSttmnt(aux, table);
    }
    return errors;
}

int checkStatList(ASTNode *node, char *table)
{
    int errors = 0;
    //Memory protection
    if (node->child != NULL)
    {
        //Call statement check
        ASTNode *aux = node->child;
        errors += checkDeclAndSttmnt(aux, table);
    }
    return errors;
}

int checkIf(ASTNode *node, char *table)
{
    int errors = 0;
    //Memory protection
    if (node->child != NULL)
    {
        //Call statement check
        ASTNode *aux = node->child;
        errors += checkDeclAndSttmnt(aux, table);
    }
    return errors;
}

int checkReturn(ASTNode *node, char *table)
{
    int errors = 0;
    //Memory protection
    if (node->child != NULL)
    {
        //Return can only be expression so its simpler
        ASTNode *aux = node->child;
        while (aux != NULL)
        {
            //Call check expr
            if (aux->isExpression)
                errors += checkExpr(aux, table);
            if (aux->next == NULL)
                break;
            aux = aux->next;
        }
    }
    return errors;
}

int checkExpr(ASTNode *node, char *table)
{
    int errors = 0;

    if (node != NULL)
    {
        if (strcmp(node->tokenType, "ChrLit") == 0)
            anotateNode(node, tree, "int");
        else if (strcmp(node->tokenType, "IntLit") == 0)
            anotateNode(node, tree, "int");
        else if (strcmp(node->tokenType, "RealLit") == 0)
            anotateNode(node, tree, "double");
        else if (strcmp(node->tokenType, "Char") == 0)
            anotateNode(node, tree, "char");
        else if (strcmp(node->tokenType, "Short") == 0)
            anotateNode(node, tree, "double");
        else if (strcmp(node->tokenType, "Int") == 0)
            anotateNode(node, tree, "int");
        else if (strcmp(node->tokenType, "Double") == 0)
            anotateNode(node, tree, "double");
        else if (strcmp(node->tokenType, "Id") == 0)
        {
            symb *auxSymb = searchSymb(table, node->tokenLval);
            if (auxSymb == NULL)
            {
                auxSymb = searchSymb("Global", node->tokenLval);
                if (auxSymb == NULL)
                {
                    if (e3)
                    {
                        errors += semanticError(8, node, "", node->line, node->col - strlen(node->tokenLval));
                    }
                    anotateNode(node, tree, "undef");
                }
                else
                {
                    anotateNode(node, tree, auxSymb->type);
                }
            }
            else
            {
                anotateNode(node, tree, auxSymb->type);
            }
        }
        else if (strcmp(node->tokenType, "Store") == 0)
        {
            if (node->child != NULL)
            {
                makeAnotation(node, table);
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (strcmp(node->child->tokenLval, "") == 0)
                    {
                        errors += semanticError(3, node->child, "", node->child->line, node->child->col - strlen(node->child->tokenLval));
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Add") == 0)
        {

            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (node->child->next != NULL)
                {
                    setNote(node, table);
                    if (e3)
                    {
                        if (node->child->next != NULL)
                        {
                            if (isArithmeticType(node->child->note))
                            {
                                if (!isArithmeticType(node->child->next->note))
                                    errors += semanticError(5, node->child->next, "+", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                            }
                            else
                            {
                                errors += semanticError(5, node->child, "+", node->child->line, node->child->col - strlen(node->child->tokenLval));
                            }
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Sub") == 0)
        {
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (node->child->next != NULL)
                {
                    setNote(node, table);
                    if (e3)
                    {
                        if (node->child->next != NULL)
                        {
                            if (isArithmeticType(node->child->note))
                            {
                                if (!isArithmeticType(node->child->next->note))
                                    errors += semanticError(5, node->child->next, "-", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                            }
                            else
                            {
                                errors += semanticError(5, node->child, "-", node->child->line, node->child->col - strlen(node->child->tokenLval));
                            }
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Mul") == 0)
        {
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);

                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (node->child->next != NULL)
                {
                    setNote(node, table);
                    if (e3)
                    {
                        if (node->child->next != NULL)
                        {
                            if (isArithmeticType(node->child->note))
                            {
                                if (!isArithmeticType(node->child->next->note))
                                    errors += semanticError(5, node->child->next, "*", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                            }
                            else
                            {
                                errors += semanticError(5, node->child, "*", node->child->line, node->child->col - strlen(node->child->tokenLval));
                            }
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Div") == 0)
        {
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (node->child->next != NULL)
                {
                    setNote(node, table);
                    if (e3)
                    {
                        if (isArithmeticType(node->child->note))
                        {
                            if (!isArithmeticType(node->child->next->note))
                                errors += semanticError(5, node->child->next, "/", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "/", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Mod") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
            }

            if (e3)
            {
                if (node->child->next != NULL)
                {
                    if (strcmp(node->child->note, "int") == 0)
                    {
                        if (strcmp(node->child->next->note, "int") != 0)
                            errors += semanticError(5, node->child->next, "%", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                    }
                    else
                    {
                        errors += semanticError(5, node->child, "%", node->child->line, node->child->col - strlen(node->child->tokenLval));
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Or") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (isRealType(node->child->note))
                        {
                            if (!isRealType(node->child->next->note))
                                errors += semanticError(5, node->child->next, "||", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "||", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "And") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (isRealType(node->child->note))
                        {
                            if (!isRealType(node->child->next->note))
                                errors += semanticError(5, node->child->next, "&&", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "&&", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "BitWiseAnd") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (strcmp(node->child->note, "int") == 0)
                        {
                            if (strcmp(node->child->next->note, "int") != 0)
                                errors += semanticError(5, node->child->next, "&", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "&", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "BitWiseOr") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (strcmp(node->child->note, "int") == 0)
                        {
                            if (strcmp(node->child->next->note, "int") != 0)
                                errors += semanticError(5, node->child->next, "|", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "|", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "BitWiseXor") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (strcmp(node->child->note, "int") == 0)
                        {
                            if (strcmp(node->child->next->note, "int") != 0)
                                errors += semanticError(5, node->child->next, "^", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "^", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Eq") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (isArithmeticType(node->child->note))
                        {
                            if (!isArithmeticType(node->child->next->note))
                                errors += semanticError(5, node->child->next, "==", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "==", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Ne") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (isArithmeticType(node->child->note))
                        {
                            if (!isArithmeticType(node->child->next->note))
                                errors += semanticError(5, node->child->next, "!=", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "!=", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Le") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (isArithmeticType(node->child->note))
                        {
                            if (!isArithmeticType(node->child->next->note))
                                errors += semanticError(5, node->child->next, "<=", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, "<=", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Ge") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (isArithmeticType(node->child->note))
                        {
                            if (!isArithmeticType(node->child->next->note))
                                errors += semanticError(5, node->child->next, ">=", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }
                        else
                        {
                            errors += semanticError(5, node->child, ">=", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Lt") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (node->child->next != NULL)
                    {
                        if (!isArithmeticType(node->child->note))
                        {
                            if (!isArithmeticType(node->child->next->note))
                                errors += semanticError(5, node->child->next, "<", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                        }

                        else
                        {
                            errors += semanticError(5, node->child, "<", node->child->line, node->child->col - strlen(node->child->tokenLval));
                        }
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Gt") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
            }
            if (e3)
            {
                if (node->child->next != NULL)
                {
                    if (isArithmeticType(node->child->note))
                    {
                        if (!isArithmeticType(node->child->next->note))
                            errors += semanticError(5, node->child->next, ">", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                    }
                    else
                    {
                        errors += semanticError(5, node->child, ">", node->child->line, node->child->col - strlen(node->child->tokenLval));
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Plus") == 0)
        {
            if (node->child != NULL)
            {
                anotateNode(node, tree, getNote(node->child, table));
                ASTNode *aux = node->child;
                while (aux != NULL)
                {

                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                anotateNode(node, tree, node->child->note);

                if (e3)
                {
                    if (!isArithmeticType(node->child->note))
                    {
                        errors += semanticError(4, node, "+", node->line, node->col - strlen(node->tokenLval));
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Minus") == 0)
        {
            if (node->child != NULL)
            {
                anotateNode(node, tree, getNote(node->child, table));
                ASTNode *aux = node->child;
                while (aux != NULL)
                {

                    if (aux->isExpression)
                        errors += checkExpr(aux, table);

                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                anotateNode(node, tree, node->child->note);
                if (e3)
                {
                    if (!isArithmeticType(node->child->note))
                    {
                        errors += semanticError(4, node, "-", node->line, node->col - strlen(node->tokenLval));
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Not") == 0)
        {
            anotateNode(node, tree, "int");
            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (e3)
                {
                    if (!isArithmeticType(node->child->note))
                    {
                        errors += semanticError(5, node, "!", node->line, node->col - strlen(node->tokenLval));
                    }
                }
            }
        }
        else if (strcmp(node->tokenType, "Call") == 0)
        {
            if (node->child != NULL)
            {
                if (node->child->next != NULL)
                {
                    ASTNode *aux = node->child->next;
                    while (aux != NULL)
                    {
                        if (aux->isExpression)
                            errors += checkExpr(aux, table);
                        if (aux->next == NULL)
                            break;
                        aux = aux->next;
                    }
                }

                symb *auxSymbGlobal = searchSymb("Global", node->child->tokenLval);

                if (auxSymbGlobal == NULL || strcmp(auxSymbGlobal->tparam, "") == 0)
                {
                    if (3)
                        errors += semanticError(7, node->child, "", node->child->line, node->child->col - strlen(node->child->tokenLval));

                    anotateNode(node, tree, "undef");
                    anotateNode(node->child, tree, "undef");
                }
                else
                {
                    anotateNode(node, tree, auxSymbGlobal->type);
                    char *buff = (char *)malloc((strlen(auxSymbGlobal->type) + strlen("(") + strlen(auxSymbGlobal->tparam) + strlen(")")) * sizeof(char));
                    sprintf(buff, "%s(%s)", auxSymbGlobal->type, auxSymbGlobal->tparam);
                    anotateNode(node->child, tree, buff);
                    free(buff);

                    if (e3)
                        errors += semanticError(9, node, "", node->child->line, node->child->col - strlen(node->child->tokenLval));
                }
            }
        }
        else if (strcmp(node->tokenType, "Comma") == 0)
        {

            if (node->child != NULL)
            {
                ASTNode *aux = node->child;
                while (aux != NULL)
                {
                    if (aux->isExpression)
                        errors += checkExpr(aux, table);
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
                if (node->child->next != NULL)
                {
                    anotateNode(node, tree, node->child->next->note);
                }
            }
        }
    }
    return errors;
}

int checkFuncBody(ASTNode *node, char *table)
{
    //Check for errors in function body
    int errors = 0;

    //Node->child can be Declaration and/or Statement
    if (node->child != NULL)
    {
        //Just traverse every funcbody->chiild can be
        ASTNode *aux = node->child;
        while (aux != NULL)
        {
            //Declaration
            if (strcmp(aux->tokenType, "Declaration") == 0)
            {
                errors += checkDecl(aux, table);
            }

            //Statlist
            if (strcmp(aux->tokenType, "StatList") == 0)
            {
                errors += checkStatList(aux, table);
            }

            //While
            if (strcmp(aux->tokenType, "While") == 0)
            {
                errors += checkWhile(aux, table);
            }

            //If
            if (strcmp(aux->tokenType, "If") == 0)
            {
                errors += checkIf(aux, table);
            }

            //Return
            if (strcmp(aux->tokenType, "Return") == 0)
            {
                errors += checkReturn(aux, table);
            }

            //Expression
            if (aux->isExpression)
            {
                errors += checkExpr(aux, table);
            }

            //Next node
            if (aux->next == NULL)
                break;
            aux = aux->next;
        }
    }
    return errors;
}

int checkFuncDef(ASTNode *node)
{
    //Check for errors in func definition
    int errors = 0;

    //Keep table name in memory to know where the symbols should be added
    char *table;

    //Param list of a function
    char tparam[255] = "";

    //Unsafe memory access protection
    if (node->child != NULL && node->child->next != NULL)
    {
        //Add input param to tparam
        if (node->child->next->next->child->child != NULL)
        {
            ASTNode *aux = node->child->next->next->child;
            while (aux != NULL)
            {
                strcat(tparam, aux->child->tokenType);
                if (aux->next == NULL)
                    break;
                strcat(tparam, ",");
                aux = aux->next;
            }
            //Insert new symbol with tparams to global table
            insertSymb("Global", node->child->next->tokenLval, node->child->tokenType, tparam, 0);
        }

        symbTab *aux;
        if ((aux = searchTab(node->child->next->tokenLval)))
        {
            if (aux->isDefined)
            {
                if (e3)
                {
                    errors += semanticError(6, node->child->next, "", node->child->next->line, node->child->next->col - strlen(node->child->next->tokenLval));
                }
            }
        }

        //Create new table for the defined function
        if (insertTab(node->child->next->tokenLval, 1) == NULL)
        {
            setAsDefined(node->child->next->tokenLval);
        }

        //And save its name to later add declarations of variables to the right table
        table = (char *)strdup(node->child->next->tokenLval);

        //Insert return with function type
        insertSymb(node->child->next->tokenLval, "return", node->child->tokenType, "", 0);

        //Once again protect against unsafe memory access
        if (node->child->next->next->child != NULL)
        {
            //Insert input params into the respective table
            ASTNode *aux = node->child->next->next->child;
            while (aux != NULL)
            {
                //I know its input param because isParam is set to one
                //This is then checked in the print function and prints "param"
                if (aux->child != NULL && aux->child->next != NULL)
                    insertSymb(table, aux->child->next->tokenLval, aux->child->tokenType, "", 1);

                if (aux->next == NULL)
                    break;
                aux = aux->next;
            }
        }

        //Check function body for variable declarations
        if (node->child->next->next->next != NULL)
        {
            //Also search for errors
            errors += checkFuncBody(node->child->next->next->next, table);
        }
    }

    //Evaluate next node
    if (node->next != NULL)
    {
        //If it is a function definition
        if (strcmp(node->next->tokenType, "FuncDefinition") == 0)
        {
            errors += checkFuncDef(node->next);
        }

        //If it is a function declaration
        if (strcmp(node->next->tokenType, "FuncDeclaration") == 0)
        {
            errors += checkFuncDecl(node->next);
        }

        //If it is a variable declaration
        if (strcmp(node->next->tokenType, "Declaration") == 0)
        {
            errors += checkDecl(node->next, "Global");
        }
    }

    return errors;
}

int checkFuncDecl(ASTNode *node)
{
    int errors = 0;
    char *table;
    //Unsafe memory access protected
    if (node->child != NULL && node->child->next != NULL)
    {
        //Check if it has input params
        if (node->child->next->next->child != NULL)
        {
            char tparam[255] = "";

            //Append input params to be inserted in Global table
            //Get type
            ASTNode *aux = node->child->next->next->child;
            while (aux != NULL)
            {
                //Append type to tparam string construct
                strcat(tparam, aux->child->tokenType);
                //If next is null string ends
                if (aux->next == NULL)
                    break;
                //If not string doesn't end apply formatting
                strcat(tparam, ",");

                //Proceed
                aux = aux->next;
            }
            if (strstr(strlwr(tparam), "void") != NULL && strlen(tparam) > strlen("Void"))
            {
                if (e3)
                {
                    aux = node->child->next->next->child;
                    while (aux != NULL)
                    {
                        if (strcmp(aux->child->tokenType, "Void") == 0)
                        {
                            errors += semanticError(2, node, "", aux->child->line, aux->child->col - strlen("void"));
                        }
                        if (aux->next == NULL)
                            break;
                        aux = aux->next;
                    }
                }
            }
            else
            {
                //Insert symbol with tparam to global table
                insertSymb("Global", node->child->next->tokenLval, node->child->tokenType, tparam, 0);
            }
        }

        //Create undefined table for function decl
        //If it is undefined its not printed
        insertTab(node->child->next->tokenLval, 0);
        //Save table name
        table = (char *)strdup(node->child->next->tokenLval);
        //Insert return everytime
        insertSymb(node->child->next->tokenLval, "return", node->child->tokenType, "", 0);
    }

    //Evaluate next node
    if (node->next != NULL)
    {
        //If it is a function definition
        if (strcmp(node->next->tokenType, "FuncDefinition") == 0)
        {
            errors += checkFuncDef(node->next);
        }

        //If it is a function declaration
        if (strcmp(node->next->tokenType, "FuncDeclaration") == 0)
        {
            errors += checkFuncDecl(node->next);
        }

        //If it is a variable declaration
        if (strcmp(node->next->tokenType, "Declaration") == 0)
        {
            errors += checkDecl(node->next, "Global");
        }
    }

    return errors;
}

int checkDecl(ASTNode *node, char *table)
{
    int errors = 0;
    //Unsafe memory access protected
    if (node->child != NULL && node->child->next != NULL)
    {
        //Check for expressions in declaration
        ASTNode *aux = node->child;
        while (aux != NULL)
        {
            if (aux->isExpression)
                errors += checkExpr(aux, table);
            if (aux->next == NULL)
                break;
            aux = aux->next;
        }
        //Simply insert symbol into designated table
        insertSymb(table, node->child->next->tokenLval, node->child->tokenType, "", 0);
    }

    //Evaluate next node
    if (node->next != NULL)
    {
        //If it is a function definition
        if (strcmp(node->next->tokenType, "FuncDefinition") == 0)
        {
            errors += checkFuncDef(node->next);
        }

        //If it is a function declaration
        if (strcmp(node->next->tokenType, "FuncDeclaration") == 0)
        {
            errors += checkFuncDecl(node->next);
        }

        //If it is a variable declaration
        if (strcmp(node->next->tokenType, "Declaration") == 0)
        {
            errors += checkDecl(node->next, table);
        }
    }

    return errors;
}

int checkTree(ASTNode *root)
{
    //Start tree semantic error count
    int errors = 0;

    //Insert hardcoded symbols into global table
    symbTables = insertTab("Global", 1);
    insertSymb("Global", "putchar", "int", "int", 0);
    insertSymb("Global", "getchar", "int", "void", 0);

    //Avaluate Program child and check accordingly
    if (root->child != NULL)
    {
        //If it is a function definition
        if (strcmp(root->child->tokenType, "FuncDefinition") == 0)
        {
            errors += checkFuncDef(root->child);
        }

        //If it is a function declaration
        if (strcmp(root->child->tokenType, "FuncDeclaration") == 0)
        {
            errors += checkFuncDecl(root->child);
        }

        //If it is a variable declaration
        if (strcmp(root->child->tokenType, "Declaration") == 0)
        {
            errors += checkDecl(root->child, "Global");
        }
    }
    return errors;
}

int semanticError(int error, ASTNode *node, char *errorInfo, int nline, int ncol)
{
    if (node == NULL)
    {
        return -1;
    }

    int argumentsRequired;
    int argumentsProvided;
    symb *auxSymbGlobal;
    symbTab *auxTab;

    switch (error)
    {
    case 1:
        printf("Line %d, col %d: Conflicting types (got %s, expected %s)\n", nline, ncol, strlwr(node->note), errorInfo);
        break;
    case 2:
        printf("Line %d, col %d: Invalid use of void type in declaration\n", nline, ncol);
        break;
    case 3:
        printf("Line %d, col %d: Lvalue required\n", nline, ncol);
        break;
    case 4:
        if (node->child != NULL)
        {
            //printf("Line %d, col %d: Operator %s cannot be applied to type %s\n", nline, ncol, errorInfo, strlwr(node->child->note));
        }
        break;
    case 5:
        if (node->child != NULL && node->child->next != NULL)
        {
            //printf("Line %d, col %d: Operator %s cannot be applied to types %s, %s\n", nline, ncol, errorInfo, strlwr(node->child->note), strlwr(node->child->next->note));
        }
        break;
    case 6:
        printf("Line %d, col %d: Symbol %s already defined\n", nline, ncol, node->tokenLval);
        break;
    case 7:
        printf("Line %d, col %d: Symbol %s is not a function\n", nline, ncol, node->tokenLval);
        break;
    case 8:
        printf("Line %d, col %d: Unkown symbol %s\n", nline, ncol, node->tokenLval);
        break;
    case 9:
        argumentsRequired = 0;
        argumentsProvided = 0;
        auxSymbGlobal = searchSymb("Global", node->child->tokenLval);
        auxTab = searchTab(node->child->tokenLval);
        if (auxSymbGlobal != NULL && strcmp(auxSymbGlobal->tparam, "") != 0)
        {
            if (strstr(strlwr(auxSymbGlobal->tparam), "void") == NULL)
                argumentsRequired = countChar(auxSymbGlobal->tparam, ',') + 1;
            else
                argumentsRequired = 0;

            if (node->child->next != NULL)
            {
                ASTNode *aux = node->child->next;
                while (aux != NULL)
                {
                    argumentsProvided++;
                    if (aux->next == NULL)
                        break;
                    aux = aux->next;
                }
            }
            if (argumentsProvided != argumentsRequired)
            {
                printf("Line %d, col %d: Wrong number of arguments to function %s (got %d, required %d)\n", nline, ncol, node->child->tokenLval, argumentsProvided, argumentsRequired);
                return 1;
            }
        }
        else
            return 0;
        break;
    }
    return 1;
}

int isRealType(char *note)
{
    if (strcmp(note, "int") == 0 || strcmp(note, "double") == 0 || strcmp(note, "short") == 0 || strcmp(note, "char") == 0)
    {
        return 1;
    }
    return 0;
}

int isArithmeticType(char *note)
{
    if (strcmp(note, "int") == 0 || strcmp(note, "double") == 0 || strcmp(note, "short") == 0 || strcmp(note, "char"))
    {
        return 1;
    }
    return 0;
}