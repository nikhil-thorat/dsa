#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

/*
 * Represents Stack type.
 */
typedef struct
{
    size_t size;
    size_t capacity;
    int *elements;
} Stack;

/*
 * Creates a new Stack of a given capacity
 * and returns a pointer to it.
 */
Stack *NewStack(size_t capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->size = 0;
    stack->elements = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

/*
 * Pushes the given value onto
 * the Stack.
 * Time complexity is O(1).
 */
void Push(Stack *stack, int value)
{
    if (stack->size == stack->capacity)
    {
        puts("Stack is Full");
        return;
    }

    stack->elements[stack->size] = value;
    stack->size++;
};

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

    stack->size--;
}

/*
 * Returns the top element of
 * the Stack.
 * Time complexity is O(1).
 */
int Top(Stack *stack)
{
    return stack->elements[stack->size - 1];
}

/*
 * Searches the given value in
 * the Stack.
 * Returns 1 if found else 0.
 * Time complexity is O(N).
 */
int Search(Stack *stack, int value)
{
    for (int i = 0; i < stack->size; i++)
    {
        if (stack->elements[i] == value)
        {
            return 1;
        }
    }
    return 0;
};

/*
 * Prints the elements of
 * the Stack.
 */
void PrintElements(Stack *stack)
{
    for (int i = 0; i < stack->size; i++)
    {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

/*
 *  Frees the memory of the given
 *  Stack.
 */
void Destroy(Stack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack->elements);
    free(stack);
}

int main()
{
    Stack *stack = NewStack(5);

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
