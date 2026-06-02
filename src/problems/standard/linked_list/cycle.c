#include <stdio.h>
#include <stdlib.h>

/*
 * Represents Linked list nodes.
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
 * Represents LinkedList, contains
 * size, and pointers to head and tail.
 */
typedef struct
{
    size_t size;
    Node *head;
    Node *tail;
} LinkedList;

/*
 * Creates a new LinkedList and returns
 * a pointer to it.
 */
LinkedList *NewLinkedList()
{
    LinkedList *linked_list = (LinkedList *)malloc(sizeof(LinkedList));
    linked_list->size = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;

    return linked_list;
}

/*
 * Inserts the given data at the
 * beginning of the LinkedList.
 * Time complexity is O(1).
 */
void InsertAtHead(LinkedList *linked_list, int data)
{
    Node *new_node = NewNode(data);

    if (linked_list->head == NULL)
    {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
        return;
    }

    new_node->next = linked_list->head;
    linked_list->head = new_node;
    linked_list->size++;
}

/*
 * Inserts the given data at the
 * end of the LinkedList.
 * Time complexity is O(1).
 */
void InsertAtTail(LinkedList *linked_list, int data)
{
    Node *new_node = NewNode(data);
    if (linked_list->head == NULL)
    {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
        return;
    }

    linked_list->tail->next = new_node;
    linked_list->tail = new_node;
    linked_list->size++;
}

/*
 * Inserts the given data at the given
 * index of the LinkedList.
 * Time complexity is O(N).
 */
void InsertAtIndex(LinkedList *linked_list, int index, int data)
{

    if (index > linked_list->size || index < 0)
    {
        return;
    }

    Node *current = linked_list->head;
    Node *prev = NULL;

    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    Node *new_node = NewNode(data);
    prev->next = new_node;
    new_node->next = current;
    linked_list->size++;
}

/*
 * Delets the given value from the
 * LinkedList.
 * Time complexity is O(N).
 */
void DeleteValue(LinkedList *linked_list, int value)
{
    Node *current = linked_list->head;
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

    if (current == linked_list->head)
    {
        linked_list->head = current->next;
        current->next = NULL;
        free(current);
        linked_list->size--;
        return;
    }

    if (current == linked_list->tail)
    {
        linked_list->tail = prev;
        linked_list->tail->next = NULL;
        free(current);
        linked_list->size--;
        return;
    }

    Node *next_node = current->next;
    prev->next = next_node;
    free(current);
    linked_list->size--;
}

/*
 * Delets the given value at given
 * index from the LinkedList.
 * Time complexity is O(N).
 */
void DeleteFromIndex(LinkedList *linked_list, int index)
{

    if (index > linked_list->size || index < 0)
    {
        return;
    }

    Node *current = linked_list->head;
    if (index == 0)
    {
        linked_list->head = current->next;
        linked_list->size--;
        free(current);
        return;
    }

    Node *prev = NULL;

    for (int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    if (index == linked_list->size - 1)
    {
        linked_list->tail = prev;
        prev->next = NULL;
        linked_list->size--;
        return;
    }

    Node *next_node = current->next;
    prev->next = next_node;
    free(current);
    linked_list->size--;
}

/*
 * Searches the given value in the
 * LinkedList.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(LinkedList *linked_list, int value)
{
    Node *current = linked_list->head;
    while (current)
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
 * Reveres the given LinkedList.
 * Time complexity is O(N).
 */
void Reverse(LinkedList *linked_list)
{
    Node *current = linked_list->head;
    Node *prev = NULL;

    while (current)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    linked_list->head = prev;
}

/*
 * Prints the elements of LinkedList.
 */
void PrintElements(LinkedList *linked_list)
{
    Node *current = linked_list->head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/*
 * Frees the memory of the given Linked list.
 */
void Destroy(LinkedList *linked_list)
{
    while (linked_list->head)
    {
        Node *temp = linked_list->head;
        linked_list->head = linked_list->head->next;
        free(temp);
    };
    free(linked_list);
}

/*
 * Returns the Node at given index.
 */
Node *NodeAt(LinkedList *linked_list, int idx)
{
    Node *current = linked_list->head;

    for (int i = 0; i < idx; i++)
    {
        if (current == NULL)
        {
            return NULL;
        }

        current = current->next;
    }

    return current;
}

/*
 * Problem Statement
 * Given the head of a singly linked list,
 * determine whether the list contains a cycle
 * (loop).
 *
 * Return 1 if a cycle exists, otherwise return 0.
 *
 * Example 1:
 * Input:
 *   1 -> 2 -> 3 -> 4
 *             ^    |
 *             |____|
 *
 * Output:
 *   1
 *
 * Explanation:
 * The last node points back to node 3,
 * creating a cycle.
 *
 * Example 2:
 * Input:
 *   1 -> 2 -> 3 -> 4 -> NULL
 *
 * Output:
 *   0
 */
int FindCycle(LinkedList *linked_list)
{
    Node *slow = linked_list->head;
    Node *fast = linked_list->head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    LinkedList *linked_list = NewLinkedList();

    InsertAtHead(linked_list, 1);
    InsertAtHead(linked_list, 2);
    InsertAtHead(linked_list, 3);
    InsertAtHead(linked_list, 4);
    PrintElements(linked_list);

    int cycle = FindCycle(linked_list);
    if (cycle == 1)
    {
        puts("Cycle Found");
    }
    else
    {
        puts("Cycle not Found");
    }

    Node *last = NodeAt(linked_list, 3);
    Node *before_last = NodeAt(linked_list, 2);

    last->next = before_last;
    puts("Cycle Created Manually");

    cycle = FindCycle(linked_list);
    if (cycle == 1)
    {
        puts("Cycle Found");
    }
    else
    {
        puts("Cycle not Found");
    }

    // Destroy(linked_list);

    return 0;
}
