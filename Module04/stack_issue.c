/** heap vs stack example */
#include <stdlib.h>
#include <stdio.h>

int* second_function(int *arr, int size, int *new_size) {
    int * evens = (int *)malloc(size * sizeof(int)); // goes to the heap
    int j = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            evens[j] = arr[i];
            j++;
        }
    }
    *new_size = j;
    return evens;
}


int* first_function(int *arr, int size, int * new_size) {

    int doubled[5];
    for(int i = 0; i < size; i++) {
        doubled[i] = arr[i] * 3;
    }
    
    return second_function(doubled, size, new_size);

}



int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int new_size;
    int *evans = first_function(a, 5, &new_size);
    for(int i = 0; i < new_size; i++) {
        printf("%d\n", evans[i]);
    }
    free(evans);
    return 0;
}
