/**
 * 
 * Example code used in 'From Code to Memory'
*/
#include <stdlib.h>
#include <time.h>

typedef struct {
    int product_id;
    int inventory;
    double price;
} product;

typedef struct {
    product ** products;
    int size;
} product_list;

int function_one(int val)
{
    int a = 5;
    int b = 10;
    int c = a + b + val;
    return c;
}

int *random_array(int size)
{
    int *a = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
       a[i] = rand() % 100;
    }
    return a;
}

int *evens_only(int *arr, int size, int *new_size)
{
    int *a = (int *)malloc(size * sizeof(int));
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            a[j] = arr[i];
            j++;
        }
    }
    *new_size = j;
    return a;
}


product * create_product(int id, int inventory, double price) {
    product *p = (product *)malloc(sizeof(product));
    p->product_id = id;
    p->inventory = inventory;
    p->price = price;
    return p;
}

product_list * create_product_list(int size) {
    product_list * list = (product_list *)malloc(sizeof(product_list));
    list->products = (product **)malloc(size * sizeof(product *));
    list->size = size;
    return list;
}

void free_product_list(product_list * list) {
    for(int i = 0; i < list->size; i++) {
        free(list->products[i]);
    }
    free(list->products);
    free(list);
}

product_list * build_inv() {
    product *apples = create_product(1, 10, 5.99); 
    product *oranges = create_product(2, 5, 3.99);
    product *bananas = create_product(3, 20, 1.99);

    product_list * list = create_product_list(3);
    list->products[0] = apples;
    list->products[1] = oranges;
    list->products[2] = bananas;
    return list;
}

int main(int argc, char const *argv[])
{
    int val = function_one(5);

    int *ra = random_array(3);

    free(ra);

    int b[] = {1, 2, 3, 4};
    int rtn_size = 0;

    int *evens = evens_only(b, 4, &rtn_size);
    free(evens);

    // structs example
    product_list * inv = build_inv();
    free_product_list(inv);

}


