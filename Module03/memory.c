
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int size, int * arr) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randomize_array(int size, int * arr) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}


int * simple_array() {
    int a[10];
    randomize_array(10, a);
    printf("Printing in simple_array() ");
    print_array(10, a);
    return a;
}

int * simple_array2() {
    int *a = malloc(10 * sizeof(int));
    randomize_array(10, a);
    printf("Printing in simple_array2() ");
    print_array(10, a);
    return a;
}

/**
 * Simple function that just adds variables 
*/
int function_one(int val) {
    int a = 5;
    int b = 10;
    int c = a + b + val;
    return c;
}


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int val = function_one(5);
    int *a = simple_array();
    int *b = simple_array2();

    printf("Printing in main() \n");
    printf("printing B");
    print_array(10, b);
    printf("printing A");
    //print_array(10, a);
    free(b);
    return 0;
}
