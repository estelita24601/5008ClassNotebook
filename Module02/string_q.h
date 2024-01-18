/**
 * Questions concerning string/ char arrays in C
 * 
*/

#ifndef STRING_Q_H
#define STRING_Q_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// simple prints a string
void print_string(char *str) {
    int i = 0;
    while (true) {
        
        if(str[i] == '\0') {
            printf("Found NULL");
            break;
        } else {
            printf("%c", str[i]);
        }
        i++; // i += 1;
    } // i++, ++i;
    printf("\n");
}

void copy_array(char *dest, char *src, int size) {
    int i = 0;
    while (i < size) {
        dest[i] = src[i];
        i++;
    }
}

void string_test() {
    char *str = "Aloha!";

    print_string(str);

    char *str2 = (char *)malloc(sizeof(char) * 10);

    str2[0] = 'A';
    str2[1] = 'l';
    str2[2] = 'o';
    str2[3] = 'h';
    str2[4] = 'a';
    str2[5] = '!';

    print_string(str2);

    char small[3];
    small[0] = 'o';
    small[1] = 'h';
    small[2] = 'a';

//    strcpy(str2, small);

//    print_string(str2);

//    printf("str[4] is %c\n", str2[4]);

    copy_array(str2, small, 3);

    print_string(str2);

    free(str2);
}



#endif // STRING_Q_H