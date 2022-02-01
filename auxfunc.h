#ifndef AUXFUNC_H
#define AUXFUNC_H

//Main includes
#include "ast.h"
#include "symbtab.h"
#include "semantics.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Debug control
#define DEBUG 0

//Syntax errors available across all files
int syntaxErrors;

char *strlwr(char *str);
int getMax(int *array, int size);
char *cap(char *str);
int countChar(char *s, char c);

#endif