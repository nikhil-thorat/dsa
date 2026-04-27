#include <stdio.h>
#include <stdlib.h>

/*
 * Represents a Node for
 * the Stack.
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
 * Represents a Stack, implemented
 * using Linked list.
 */
typedef struct
{
    size_t size;
    Node *head;
    Node *tail;
} Stack;

/*
 * Creates a new Stack with given
 * capacity and returns a pointer to it.
 */
Stack *NewStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = 0;
    stack->head = NULL;
    stack->tail = NULL;
    return stack;
};

/*
 * Pushes the given value onto
 * the Stack.
 * Time complexity is O(1).
 */
void Push(Stack *stack, int value)
{
    Node *new_node = NewNode(value);
    if (stack->head == NULL)
    {
        stack->head = new_node;
        stack->tail = new_node;
        stack->size++;
        return;
    }

    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
}

/*
 * Pops the top element from the
 * Stack.
 * Time complexity is O(1).
 */
void Pop(Stack *stack)
{

    if (stack->size == 0)
    {
        puts("Stack is Empty");
        return;
    }

    Node *temp = stack->head;
    stack->head = temp->next;
    stack->size--;
    free(temp);
}

/*
 * Returns the top element of
 * the Stack.
 * Time complexity is O(1).
 */
int Top(Stack *stack)
{
    return stack->head->data;
}

/*
 * Searches the given value in
 * the Stack.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(Stack *stack, int value)
{
    Node *current = stack->head;
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
 * Prints the elements of
 * the Stack.
 */
void PrintElements(Stack *stack)
{
    Node *current = stack->head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/*
 *  Frees the memory of the given
 *  Stack.
 */
void Destroy(Stack *stack)
{
    while (stack->head)
    {
        Node *temp = stack->head;
        stack->head = stack->head->next;
        free(temp);
    }

    free(stack);
};

int main()
{
    Stack *stack = NewStack();

    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);
    Push(stack, 5);
    PrintElements(stack);

    Pop(stack);

    PrintElements(stack);
    printf("Top element : %d\n", Top(stack));

    Pop(stack);
    PrintElements(stack);
    printf("Top element : %d\n", Top(stack));

    Destroy(stack);

    return 0;
}
