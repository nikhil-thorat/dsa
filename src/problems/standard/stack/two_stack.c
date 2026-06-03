#include <stdio.h>
#include <stdlib.h>

/*
 * Problem Statement
 * Implement two independent stacks using a
 * single array such that both stacks can
 * perform push and pop operations efficiently.
 *
 * The two stacks should share the same array
 * without overlapping, and the implementation
 * should maximize the utilization of the
 * available space.
 *
 * Operations:
 *   - Push(stack_id, value)
 *   - Pop(stack_id)
 *   - IsEmpty(stack_id)
 *   - IsFull()
 *
 * Example:
 * Array Size: 10
 *
 * Stack 1 Push: 1, 2, 3
 * Stack 2 Push: 10, 20
 *
 * Array:
 * [1, 2, 3, _, _, _, _, _, 20, 10]
 *
 * Stack 1 Top: 3
 * Stack 2 Top: 20
 */

/*
 * Stack type
 */
typedef struct
{
    size_t capacity;
    int top1;
    int top2;
    int *elements;
} Stack;

Stack *NewStack(size_t capacity)
{
    Stack *stack = malloc(sizeof(Stack));

    stack->capacity = capacity;
    stack->top1 = -1;
    stack->top2 = capacity;
    stack->elements = calloc(stack->capacity, sizeof(int));

    return stack;
}

/*
 * Push function
 */
void Push(Stack *stack, int stack_id, int value)
{
    if (stack_id == 1 && stack->top1 + 1 == stack->top2)
    {
        puts("Stack 1 is Full");
        return;
    }

    if (stack_id == 2 && stack->top2 - 1 == stack->top1)
    {
        puts("Stack 2 is Full");
        return;
    }

    if (stack_id == 1)
    {
        stack->top1++;
        stack->elements[stack->top1] = value;
    }

    if (stack_id == 2)
    {
        stack->top2--;
        stack->elements[stack->top2] = value;
    }
}

/*
 * Pop function
 */
void Pop(Stack *stack, int stack_id)
{
    if (stack_id == 1 && stack->top1 == -1)
    {
        puts("Stack 1 is Empty");
        return;
    }

    if (stack_id == 2 && stack->top2 == stack->capacity)
    {
        puts("Stack 2 is Empty");
        return;
    }

    if (stack_id == 1)
    {
        stack->elements[stack->top1] = 0;
        stack->top1--;
    }

    if (stack_id == 2)
    {
        stack->elements[stack->top2] = 0;
        stack->top2++;
    }
}

/*
 * Print stack elements.
 */
void Print(Stack *stack)
{
    printf("Stack 1 : ");
    for (int i = 0; i <= stack->top1; i++)
    {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
    printf("Stack 2 : ");
    for (int i = stack->capacity - 1; i >= stack->top2; i--)
    {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");

    printf("Actual Stack : ");
    for (int i = 0; i < stack->capacity; i++)
    {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}

/*
 * Frees memory allocated to stack.
 */
void Destroy(Stack *stack)
{
    free(stack->elements);
    free(stack);
}

int main()
{
    Stack *stack = NewStack(10);

    Push(stack, 1, 1);
    Push(stack, 1, 2);
    Push(stack, 1, 3);
    Push(stack, 1, 4);
    Print(stack);

    Push(stack, 2, 1);
    Push(stack, 2, 2);
    Push(stack, 2, 3);
    Push(stack, 2, 4);
    Print(stack);

    Push(stack, 1, 5);
    Push(stack, 1, 6);
    Print(stack);

    Push(stack, 2, 5);
    Print(stack);

    Pop(stack, 1);
    Pop(stack, 2);
    Print(stack);

    Push(stack, 1, 6);
    Push(stack, 2, 6);
    Print(stack);

    Destroy(stack);

    return 0;
}
