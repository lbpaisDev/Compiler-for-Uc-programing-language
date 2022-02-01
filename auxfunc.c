#include "auxfunc.h"

char *strlwr(char *str)
{
    int i;
    for (i = 0; i <= strlen(str); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
    return str;
}

int getMax(int *array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

char *cap(char *str)
{
    int i;
    //capitalize first character of words
    for (i = 0; str[i] != '\0'; i++)
    {
        //check first character is lowercase alphabet
        if (i == 0)
        {
            if ((str[i] >= 'a' && str[i] <= 'z'))
                str[i] = str[i] - 32; //subtract 32 to make it capital
            continue;                 //continue to the loop
        }
        if (str[i] == ' ') //check space
        {
            //if space is found, check next character
            ++i;
            //check next character is lowercase alphabet
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 32; //subtract 32 to make it capital
                continue;             //continue to the loop
            }
        }
    }
    return str;
}

int countChar(char *s, char c)
{
    int i, count = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }
    return count;
}
