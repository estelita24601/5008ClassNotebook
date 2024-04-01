#include "hash_table.h"

int main()
{
    HashTable table = create_hash_table();
    print_debug("created hash table");

    add(table, "Darth Vader", "Anakin Skywalker");
    print_debug("added an item to hash table");
    add(table, "Dread Pirate Roberts", "Wesley");
    print_debug("added an item to hash table");
    add(table, "Princess Bride", "Buttercup");
    print_debug("added an item to hash table");
    add(table, "Old Ben", "Obi-Wan Kenobi");
    print_debug("added an item to hash table");

    free_table(table);
    return 0;
}