#include <stdio.h>
#include <stdlib.h>

/*
 * HashMap implementation using simple
 * modulo hashing.
 */
typedef struct
{
    size_t capacity;
    size_t size;
    int *elements;
} HashMap;

/*
 * Creates a new HashMap and returns
 * a pointer to it.
 */
HashMap *NewHashMap(size_t capacity)
{
    HashMap *hash_map = malloc(sizeof(HashMap));

    hash_map->capacity = capacity;
    hash_map->size = 0;
    hash_map->elements = malloc(sizeof(int) * capacity);

    for (int i = 0; i < hash_map->capacity; i++)
    {
        hash_map->elements[i] = -1;
    }

    return hash_map;
}

/*
 * Generates a hash for given value.
 */
int GenerateHash(size_t capacity, int key)
{
    return key % capacity;
}

/*
 * Inserts a given element in the
 * HashMap.
 */
void Set(HashMap *hash_map, int key, int value)
{
    int hash = GenerateHash(hash_map->capacity, key);
    hash_map->elements[hash] = value;
    hash_map->size++;
}

/*
 * Returns the value from the HashMap.
 */
int Get(HashMap *hash_map, int key)
{
    int hash = GenerateHash(hash_map->capacity, key);
    return hash_map->elements[hash];
}

/*
 * Deletes the value from the HashMap.
 */
void Delete(HashMap *hash_map, int key)
{
    int hash = GenerateHash(hash_map->capacity, key);
    hash_map->elements[hash] = -1;
    hash_map->size--;
}

int main()
{

    HashMap *hash_map = NewHashMap(5);

    Set(hash_map, 123, 10);
    Set(hash_map, 231, 20);
    Set(hash_map, 312, 30);

    int key = 123;
    int result = Get(hash_map, key);

    if (result != -1)
    {
        printf("Key : %d; Value : %d\n", key, result);
    }
    else
    {
        printf("Key : %d; Value : %d\n", key, result);
    }

    Delete(hash_map, key);
    result = Get(hash_map, key);

    if (result != -1)
    {
        printf("Key : %d; Value : %d\n", key, result);
    }
    else
    {
        printf("Key : %d; Value : %d\n", key, result);
    }

    return 0;
}
