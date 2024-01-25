
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point ** points;
    int size;
} point_list;


point * create_point(int x, int y) {
    point * p = malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

void print_point_list(point_list * list) {
    for(int i = 0; i < list->size; i++) {
        printf("(%d, %d) ", list->points[i]->x, list->points[i]->y);
    }
    printf("\n");
}

point_list * create_point_array(int size, int x, int y) {
    point_list * list = (point_list*) malloc(size * sizeof(point_list));
    list->points = malloc(size * sizeof(point *));
    list->size = size;

    for(int i = 0; i < size; i++) {
        list->points[i] = create_point(x+i*10, y+i*10);
    }
    return list;
}

void free_point_list(point_list * list) {
    for(int i = 0; i < list->size; i++) {
        free(list->points[i]);
    }
    free(list->points);
    free(list);
}

int does_some_math(int a, int b, int * counter) {
    int result = 1;
    for(int i = a; i < b; i++) {
        result *= i;
        (*counter)++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = 5;
    int b = 10;
    int counter = 0;
    int result = does_some_math(a, b, &counter);
    printf("Result: %d, # of times executed: %d\n", result, counter);

    point * p = create_point(5, 10);
    printf("Point: (%d, %d)\n", p->x, p->y);
    point * p2 = create_point(10, 20);
    printf("Point: (%d, %d)\n", p2->x, p2->y);

    free(p);
    free(p2);

    point_list* list = create_point_array(10, 5, 10);

    print_point_list(list);

    free_point_list(list);

    return 0;
}
