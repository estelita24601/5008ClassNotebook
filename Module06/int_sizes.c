/** Example of int sizes
 * 
 * 
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main(int argc, const char **argv) {

    int four = 0;  // 32??

    
    short two = 0;  // 16

    uint64_t eight = 0;  // 64

    

    unsigned long long eight_two = 0; // 64

    long eight_three = 0; // 32?

    printf("Size of short int: %lu\n", sizeof(two) * 8);

    printf("Size of int: %lu\n", sizeof(four) * 8);

    printf("Size of uint64_t: %lu\n", sizeof(eight) * 8);

    printf("Size of unsigned long long: %lu\n", sizeof(eight_two) * 8);

    printf("Size of long: %lu\n", sizeof(eight_three) * 8);

    return 0;



}