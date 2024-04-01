#include "hash_table.h"

int main()
{
    int table_size = 100;
    HashTable table = create_hash_table(table_size);
    printf("created table of size %d\n", table_size);

    add(table, table_size, "Darth Vader", "Anakin Skywalker");
    print_debug("added an item to hash table");

    add(table, table_size, "Dread Pirate Roberts", "Wesley");
    print_debug("added an item to hash table");

    add(table, table_size, "Princess Bride", "Buttercup");
    print_debug("added an item to hash table");

    add(table, table_size, "Old Ben", "Obi-Wan Kenobi");
    print_debug("added an item to hash table");

    add(table, table_size, "Voldemort", "Tom Marvolo Riddle");
    print_debug("added an item to hash table");

    add(table, table_size, "The Boy Who Lived", "Harry Potter");
    print_debug("added an item to hash table");

    add(table, table_size, "Captain Proton", "Tom Paris");
    print_debug("added an item to hash table");

    add(table, table_size, "007", "James Bond");
    print_debug("added an item to hash table");

    print_hash_table(table, table_size);

    char *key = "Old Ben";
    printf("trying to find value from key \"%s\":\n", key);
    char *found_value = table_get(table, table_size, key);
    printf("\tvalue = \"%s\"\n", found_value);

    key = "captain proton";
    printf("trying to find value from key \"%s\":\n", key);
    found_value = table_get(table, table_size, key);
    printf("\tvalue = \"%s\"\n", found_value);

    key = "Captain Proton";
    printf("trying to find value from key \"%s\":\n", key);
    found_value = table_get(table, table_size, key);
    printf("\tvalue = \"%s\"\n", found_value);

    free_table(table, table_size);
    return 0;
}