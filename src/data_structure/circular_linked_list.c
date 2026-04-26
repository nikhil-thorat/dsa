#include <stdio.h>
#include <stdlib.h>

/*
 * Represents Circular Linked list nodes.
 */
typedef struct Node
{
    int data;
    struct Node *next;
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

    return node;
}

/*
 * Represents CircularLinkedList, contains
 * size, and pointers to head and tail.
 */
typedef struct
{
    size_t size;
    Node *head;
    Node *tail;
} CircularLinkedList;

/*
 * Creates a new CircularLinkedList and returns
 * a pointer to it.
 */
CircularLinkedList *NewCircularLinkedList()
{
    CircularLinkedList *circular_linked_list = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
    circular_linked_list->size = 0;
    circular_linked_list->head = NULL;
    circular_linked_list->tail = NULL;

    return circular_linked_list;
}

/*
 * Inserts the give data at the
 * beginning of the CircularLinkedList.
 * Time complexity is O(1)
 */
void InsertAtHead(CircularLinkedList *circular_linked_list, int data)
{
    Node *new_node = NewNode(data);

    if (circular_linked_list->head == NULL)
    {
        circular_linked_list->head = new_node;
        circular_linked_list->tail = new_node;
        circular_linked_list->head->next = circular_linked_list->head;
        circular_linked_list->tail->next = circular_linked_list->tail;
        circular_linked_list->size++;
        return;
    }

    new_node->next = circular_linked_list->head;
    circular_linked_list->head = new_node;
    circular_linked_list->tail->next = circular_linked_list->head;
    circular_linked_list->size++;
}

/*
 * Inserts the give data at the
 * ending of the CircularLinkedList.
 * Time complexity is O(1)
 */
void InsertAtTail(CircularLinkedList *circular_linked_list, int data)
{
    Node *new_node = NewNode(data);

    if (circular_linked_list->head == NULL)
    {
        circular_linked_list->head = new_node;
        circular_linked_list->tail = new_node;
        circular_linked_list->head->next = circular_linked_list->head;
        circular_linked_list->tail->next = circular_linked_list->tail;
        circular_linked_list->size++;
        return;
    }

    circular_linked_list->tail->next = new_node;
    circular_linked_list->tail = new_node;
    circular_linked_list->tail->next = circular_linked_list->head;
    circular_linked_list->size++;
}

/*
 * Deletes the given value from the
 * CircularLinkedList.
 * Time complexity is O(N).
 */
void DeleteValue(CircularLinkedList *circular_linked_list, int value)
{
    Node *current = circular_linked_list->head;
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

    if (current == circular_linked_list->head)
    {
        circular_linked_list->head = current->next;
        current->next = NULL;
        circular_linked_list->tail->next = circular_linked_list->head;
        free(current);
        circular_linked_list->size--;
        return;
    }

    if (current == circular_linked_list->tail)
    {
        circular_linked_list->tail = prev;
        circular_linked_list->tail->next = circular_linked_list->head;
        free(current);
        circular_linked_list->size--;
        return;
    }

    Node *next_node = current->next;
    prev->next = next_node;
    free(current);
    circular_linked_list->size--;
}

/*
 * Deletes the value at given
 * index from the LinkedList.
 * Time complexity is O(N).
 */
void DeleteFromIndex(CircularLinkedList *circular_linked_list, int index)
{
    if (index > circular_linked_list->size || index < 0)
    {
        return;
    }

    Node *current = circular_linked_list->head;
    if (index == 0)
    {
        circular_linked_list->head = current->next;
        circular_linked_list->tail->next = circular_linked_list->head;
        circular_linked_list->size--;
        free(current);
        return;
    }

    Node *prev = NULL;

    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    if (index == circular_linked_list->size - 1)
    {
        circular_linked_list->tail = prev;
        circular_linked_list->tail->next = circular_linked_list->head;
        circular_linked_list->size--;
        return;
    }

    Node *next_node = current->next;
    prev->next = next_node;
    free(current);
    circular_linked_list->size--;
}

/*
 * Searches the given value in the
 * CircularLinkedList
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(CircularLinkedList *circular_linked_list, int value)
{
    Node *current = circular_linked_list->head;
    while (current)
    {
        if (current->data == value)
        {
            return 1;
        }
    }

    return 0;
}

/*
 * Prints the elements of CircularLinkedList.
 */
void PrintElements(CircularLinkedList *circularlinked_list)
{
    Node *current = circularlinked_list->head;
    while (current != circularlinked_list->tail)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

/*
 * Frees the memory of the given Circular Linked list.
 */
void Destroy(CircularLinkedList *circular_linked_list)
{
    while (circular_linked_list->head->next != circular_linked_list->head)
    {
        Node *temp = circular_linked_list->head;
        circular_linked_list->head = circular_linked_list->head->next;
        free(temp);
    }
    free(circular_linked_list);
}

int main()
{
    CircularLinkedList *circular_linked_list = NewCircularLinkedList();

    InsertAtHead(circular_linked_list, 1);
    InsertAtHead(circular_linked_list, 2);
    InsertAtHead(circular_linked_list, 3);
    InsertAtHead(circular_linked_list, 4);
    PrintElements(circular_linked_list);

    InsertAtTail(circular_linked_list, 5);
    PrintElements(circular_linked_list);

    InsertAtTail(circular_linked_list, 6);
    PrintElements(circular_linked_list);

    int value = 4;
    int result = Search(circular_linked_list, value);
    if (result == 1)
    {
        printf("%d Exists in the Circular linked list\n", value);
    }
    else
    {
        printf("%d Does not exists in the Circular linked list\n", value);
    }

    DeleteValue(circular_linked_list, 4);
    PrintElements(circular_linked_list);

    DeleteValue(circular_linked_list, 6);
    PrintElements(circular_linked_list);

    DeleteValue(circular_linked_list, 2);
    PrintElements(circular_linked_list);

    DeleteFromIndex(circular_linked_list, 1);
    PrintElements(circular_linked_list);

    InsertAtTail(circular_linked_list, 6);
    PrintElements(circular_linked_list);

    return 0;
}
