#include <stdio.h>
#include <stdlib.h>

/*
 * Represents the Node of HashMap
 */
typedef struct Node Node;
typedef struct Node
{
    int data;
    Node *next;
} Node;

/*
 * Creates a Node and returns
 * a pointer to it.
 */
Node *NewNode(int value)
{
    Node *node = malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;

    return node;
}

/*
 * HashMap implementation using Seperate Chaining
 * for collision resolution.
 */
typedef struct
{
    size_t capacity;
    size_t size;
    Node **elements;
} HashMap;

/*
 * Creates a Hashmap and returns
 * a pointer to it.
 */
HashMap *NewHashMap(size_t capacity)
{
    HashMap *hash_map = malloc(sizeof(HashMap));

    hash_map->capacity = capacity;
    hash_map->size = 0;
    hash_map->elements = malloc(sizeof(Node *) * hash_map->capacity);

    for (int i = 0; i < hash_map->capacity; i++)
    {
        hash_map->elements[i] = NULL;
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
    Node *new_node = NewNode(value);
    new_node->next = hash_map->elements[key];
    hash_map->elements[key] = new_node;

    hash_map->size++;
}

/*
 * Returns 1 if value exists in HashMap else 0.
 */
int Get(HashMap *hash_map, int value)
{
    int key = value % hash_map->capacity;

    Node *current = hash_map->elements[key];
    while (current != NULL)
    {
        if (current->data == value)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

/*
 * Deletes the value from the HashMap.
 */
void Delete(HashMap *hash_map, int value)
{
    int key = value % hash_map->capacity;

    Node *prev = NULL;
    Node *current = hash_map->elements[key];

    if (current->data == value)
    {
        hash_map->elements[key] = current->next;
        free(current);
        return;
    }

    while (current != NULL)
    {

        if (current->data == value)
        {
            prev->next = current->next;
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }

    hash_map->size--;
}

/*
 * Prints the elements of the HashMap
 */
void Print(HashMap *hash_map)
{
    for (int i = 0; i < hash_map->capacity; i++)
    {

        Node *current = hash_map->elements[i];
        while (current != NULL)
        {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main()
{

    HashMap *hash_map = NewHashMap(8);

    Set(hash_map, 10);
    Set(hash_map, 20);
    Set(hash_map, 30);
    Set(hash_map, 40);
    Set(hash_map, 50);

    Print(hash_map);

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
    Print(hash_map);

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
