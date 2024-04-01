#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random_key_gen.c"
typedef unsigned long ul; // nickname for unsigned long

// receive a string key and turn into an unsigned long number
ul djb2(char *str)
{
    ul hash = 5381;
    int char_address;

    // at top of every loop increment the char_address to the next address in the string
    // if next address in string is for \0 then the loop stops HOW/WHY?
    while ((char_address = *str++))
    {
        hash = (hash + (hash << 5)) + char_address;
    }

    return hash;
}

void first_test()
{
    int arr_size = 100;

    char *random_key = random_string(5);
    ul hashcode = djb2(random_key);
    printf("key = %s\thashes to %lu\n", random_key, hashcode % arr_size);

    shuffle_string(random_key);
    printf("\tshuffling...\n");

    shuffle_string(random_key);
    hashcode = djb2(random_key);
    printf("key = %s\thashes to %lu\n", random_key, hashcode % arr_size);
}

int check_for_collisions(int *array, ul hash)
{
    if (array[hash] > 0)
    {
        array[hash] = array[hash] + 1;
        return 1;
    }
    else
    {
        array[hash] = 1;
        return 0;
    }
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            printf("\t%d\n", arr[i]);
        }
    }
}

int main()
{
    int collisions = 0;
    int arr_size = 500;
    int *array = malloc(sizeof(int) * arr_size); // QUESTION: when made array with brackets program didn't work?

    printf("creating %d random strings\n", 200);

    for (int i = 0; i < 100; i++)
    {
        char *rand_string = random_string(5);
        ul hash = djb2(rand_string) % arr_size;
        collisions += check_for_collisions(array, hash);

        shuffle_string(rand_string);
        hash = djb2(rand_string) % arr_size;
        collisions += check_for_collisions(array, hash);
    }

    printf("%d collisions in an array with %d spots\n", collisions, arr_size);
    printf("\ncollision distribution:\n");
    print_arr(array, arr_size);

    free(array);
    return 0;
}