#include <stdio.h>
#include <stdlib.h>

/*
 * HashMap implementation using Linear Probing
 * for collision resolution.
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
 * Inserts a given element in the
 * HashMap.
 */
void Set(HashMap *hash_map, int value)
{

    if (hash_map->size == hash_map->capacity)
    {
        puts("HashMap is Full");
        return;
    }

    int key = value % hash_map->capacity;
    int idx = key;

    while (hash_map->elements[idx] != -1)
    {
        idx = (idx + 1) % hash_map->capacity;
        if (idx == key)
        {
            puts("HashMap is Full");
            return;
        }
    }

    hash_map->elements[idx] = value;
    hash_map->size++;
}

/*
 * Returns 1 if value exists in HashMap else 0.
 */
int Get(HashMap *hash_map, int value)
{
    int key = value % hash_map->capacity;
    int idx = key;

    while (hash_map->elements[idx] != -1)
    {
        idx = (idx + 1) % hash_map->capacity;

        if (idx == key)
        {
            return 0;
        }

        if (hash_map->elements[key] == value)
        {
            return 1;
        }
    }

    return 0;
}

/*
 * Deletes the value from the HashMap.
 */
void Delete(HashMap *hash_map, int value)
{
    int key = value % hash_map->capacity;
    if (hash_map->elements[key] == value)
    {
        hash_map->elements[key] = -1;
        hash_map->size--;
        return;
    }

    int idx = key;
    while (hash_map->elements[idx] != -1)
    {
        idx = (idx + 1) % hash_map->capacity;

        if (idx == key)
        {
            return;
        }
    }

    hash_map->elements[idx] = -1;
    hash_map->size--;
}

int main()
{

    HashMap *hash_map = NewHashMap(5);

    Set(hash_map, 10);
    Set(hash_map, 20);
    Set(hash_map, 30);

    int value = 10;

    int result = Get(hash_map, value);
    if (result == 1)
    {
        printf("%d exists in HashMap\n", value);
    }
    else
    {
        printf("%d does not exist in HashMap\n", value);
    }

    Delete(hash_map, value);

    result = Get(hash_map, value);
    if (result == 1)
    {
        printf("%d exists in HashMap\n", value);
    }
    else
    {
        printf("%d does not exist in HashMap\n", value);
    }

    return 0;
}
