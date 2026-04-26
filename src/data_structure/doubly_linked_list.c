#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Represents Doubly Linked list nodes.
 */
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

/*
 * Creates a new Node with given data, and sets
 * the next pointer to NULL and returns a pointer
 * to it.
 */
Node *NewNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

/*
 * Represents DoublyLinkedList, contains
 * size, and pointers to head and tail.
 */
typedef struct
{
    size_t size;
    Node *head;
    Node *tail;
} DoublyLinkedList;

/*
 * Creates a new DoublyLinkedList and returns
 * a pointer to it.
 */
DoublyLinkedList *NewDoublyLinkedList()
{
    DoublyLinkedList *doubly_linked_list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    doubly_linked_list->size = 0;
    doubly_linked_list->head = NULL;
    doubly_linked_list->tail = NULL;

    return doubly_linked_list;
}

/*
 * Inserts the given data at the
 * beginning of the DoublyLinkedList.
 * Time complexity is O(1).
 */
void InsertAtHead(DoublyLinkedList *doubly_linked_list, int data)
{
    Node *new_node = NewNode(data);

    if (doubly_linked_list->head == NULL)
    {
        doubly_linked_list->head = new_node;
        doubly_linked_list->tail = new_node;
        doubly_linked_list->size++;
        return;
    }

    new_node->next = doubly_linked_list->head;
    doubly_linked_list->head->prev = new_node;
    doubly_linked_list->head = new_node;
    doubly_linked_list->size++;
}

/*
 * Inserts the given data at the
 * end of the DoublyLinkedList.
 * Time complexity is O(1).
 */
void InsertAtTail(DoublyLinkedList *doubly_linked_list, int data)
{
    Node *new_node = NewNode(data);

    if (doubly_linked_list->head == NULL)
    {
        doubly_linked_list->head = new_node;
        doubly_linked_list->tail = new_node;
        doubly_linked_list->size++;
        return;
    }

    doubly_linked_list->tail->next = new_node;
    new_node->prev = doubly_linked_list->tail;
    doubly_linked_list->tail = new_node;
    doubly_linked_list->size++;
}

/*
 * Inserts the given data at the given
 * index of the DoublyLinkedList.
 * Time complexity is O(N).
 */
void InsertAtIndex(DoublyLinkedList *doubly_linked_list, int index, int data)
{

    if (index > doubly_linked_list->size)
    {
        return;
    }

    if (index == 0)
    {
        InsertAtHead(doubly_linked_list, data);
    }

    if (index == doubly_linked_list->size - 1)
    {
        InsertAtTail(doubly_linked_list, data);
    }

    Node *current = doubly_linked_list->head;
    Node *prev = NULL;

    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    Node *new_node = NewNode(data);
    prev->next = new_node;
    new_node->prev = prev;
    new_node->next = current;
    current->prev = new_node;
    doubly_linked_list->size++;
}

/*
 * Delets the given value from the
 * DoublyLinkedList.
 * Time complexity is O(N).
 */
void DeleteValue(DoublyLinkedList *doubly_linked_list, int value)
{
    Node *current = doubly_linked_list->head;
    Node *prev = NULL;

    while (current)
    {
        if (current->data == value)
        {
            break;
        }

        prev = current;
        current = current->next;
    }

    if (current == doubly_linked_list->head)
    {
        doubly_linked_list->head = current->next;
        current->next = NULL;
        doubly_linked_list->head->prev = NULL;
        free(current);
        doubly_linked_list->size--;
        return;
    }

    if (current == doubly_linked_list->tail)
    {
        doubly_linked_list->tail = current->prev;
        current->next = NULL;
        doubly_linked_list->tail->next = NULL;
        free(current);
        doubly_linked_list->size--;
        return;
    }

    Node *next_node = current->next;
    prev->next = next_node;
    next_node->prev = prev;
    doubly_linked_list->size--;
    free(current);
}

/*
 * Delets the given value at given
 * index from the DoublyLinkedList.
 * Time complexity is O(N).
 */
void DeleteFromIndex(DoublyLinkedList *doubly_linked_list, int index)
{
    if (index > doubly_linked_list->size || index < 0)
    {
        return;
    }

    if (doubly_linked_list->size == 1)
    {
        doubly_linked_list->head = NULL;
        doubly_linked_list->tail = NULL;
        doubly_linked_list->size--;
        return;
    };

    Node *current = doubly_linked_list->head;
    if (index == 0)
    {
        doubly_linked_list->head = current->next;
        current->next = NULL;
        doubly_linked_list->head->prev = NULL;
        free(current);
        doubly_linked_list->size--;
        return;
    }

    Node *prev = NULL;

    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    if (index == doubly_linked_list->size - 1)
    {
        doubly_linked_list->tail = current->prev;
        doubly_linked_list->tail->next = NULL;
        current->prev = NULL;
        free(current);
        doubly_linked_list->size--;
        return;
    }

    Node *next_node = current->next;
    prev->next = next_node;
    next_node->prev = prev;
    doubly_linked_list->size--;
    free(current);
}

/*
 * Searches the given value in the
 * DoublyLinkedList.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(DoublyLinkedList *doubly_linked_list, int value)
{
    Node *current = doubly_linked_list->head;
    while (current)
    {
        if (current->data == value)
        {
            return 1;
        }
        current = current->next;
    }
    free(current);
    return 0;
}

/*
 * Reveres the given DoublyLinkedList.
 * Time complexity is O(N).
 */
void Reverse(DoublyLinkedList *doubly_linked_list)
{
    Node *current = doubly_linked_list->head;
    Node *prev = NULL;

    while (current)
    {
        Node *next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    doubly_linked_list->tail = doubly_linked_list->head;
    doubly_linked_list->head = prev;
    free(current);
}

/*
 * Prints the elements of DoublyLinkedList.
 */
void PrintElements(DoublyLinkedList *doubly_linked_list)
{

    Node *current = doubly_linked_list->head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    free(current);
}

/*
 * Frees the memory of the given Doubly linked list.
 */
void Destroy(DoublyLinkedList *doubly_linked_list)
{
    while (doubly_linked_list->head)
    {
        Node *temp = doubly_linked_list->head;
        doubly_linked_list->head = doubly_linked_list->head->next;
        free(temp);
    }
    free(doubly_linked_list);
}

int main()
{
    DoublyLinkedList *doubly_linked_list = NewDoublyLinkedList();

    InsertAtHead(doubly_linked_list, 1);
    InsertAtHead(doubly_linked_list, 2);
    InsertAtHead(doubly_linked_list, 3);
    InsertAtHead(doubly_linked_list, 4);
    PrintElements(doubly_linked_list);

    InsertAtTail(doubly_linked_list, 5);
    PrintElements(doubly_linked_list);

    InsertAtIndex(doubly_linked_list, 2, 0);
    PrintElements(doubly_linked_list);

    DeleteValue(doubly_linked_list, 0);
    PrintElements(doubly_linked_list);

    DeleteValue(doubly_linked_list, 2);
    PrintElements(doubly_linked_list);

    int value = 1;
    int found = Search(doubly_linked_list, value);
    if (found)
    {
        printf("Value %d is presnet in DoublyLinkedList\n", value);
    }
    else
    {
        printf("Value %d is not presnet in DoublyLinkedList\n", value);
    }

    Reverse(doubly_linked_list);
    PrintElements(doubly_linked_list);

    DeleteValue(doubly_linked_list, 5);
    PrintElements(doubly_linked_list);

    DeleteValue(doubly_linked_list, 4);
    PrintElements(doubly_linked_list);

    DeleteFromIndex(doubly_linked_list, 1);
    PrintElements(doubly_linked_list);

    DeleteFromIndex(doubly_linked_list, 0);
    PrintElements(doubly_linked_list);

    Destroy(doubly_linked_list);

    return 0;
}
