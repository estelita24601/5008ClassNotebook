/**
 * 
 * Quick file reading example
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
int main()
{
    FILE *file = fopen("raven.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char line[BUFFER_SIZE];
    char *result = (char *)malloc(BUFFER_SIZE * sizeof(char));
    while (fgets(line, BUFFER_SIZE, file) != NULL) // if EOF, return NULL
    {
        strcpy(result, line);
        result[0] = 'X';
        printf("LINE: %s", line);
        printf("RESULT: %s", result);
    }
    free(result);

    fclose(file);
    return 0;
}