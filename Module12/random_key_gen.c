/**
 * Simple set of functions to generate random keys for testing functions
 */
#ifndef RANDOM_KEY_GEN
#define RANDOM_KEY_GEN

#include <stdlib.h>
#include <time.h>
#include <string.h>

char random_character()
{
    return 'A' + (rand() % 26);
}

char *random_string(int length)
{
    char *str = (char *)malloc(sizeof(char) * length + 1);
    for (int i = 0; i < length; i++)
    {
        str[i] = random_character();
    }
    str[length] = '\0';
    return str;
}

void shuffle_string(char *str)
{
    int length = strlen(str);
    int i;
    for (i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

#endif