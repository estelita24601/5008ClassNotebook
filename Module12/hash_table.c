#include "hash_table.h"

int main()
{
    int table_size = 100;
    HashTable table = create_hash_table(table_size);
    printf("created table of size %d\n\n", table_size);

    add(table, table_size, "Darth Vader", "Anakin Skywalker");
    print_debug("added an item to hash table");

    add(table, table_size, "Dread Pirate Roberts", "Wesley");
    print_debug("added an item to hash table");

    add(table, table_size, "Princess Bride", "Buttercup");
    print_debug("added an item to hash table");

    add(table, table_size, "Old Ben", "Obi-Wan Kenobi");
    print_debug("added an item to hash table");

    free_table(table, table_size);
    return 0;
}