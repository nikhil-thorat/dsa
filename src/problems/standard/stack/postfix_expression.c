#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int Pop(Stack *stack)
{
    if (stack->size == 0)
    {
        puts("Stack is Empty");
        return ' ';
    }

    char ch = stack->elements[stack->size - 1];
    stack->size--;

    return ch;
}

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

/*
 * Problem Statement
 * Given a valid postfix expression, evaluate
 * the expression and return the final result.
 *
 * A postfix expression (Reverse Polish Notation)
 * is an expression in which operators appear
 * after their operands.
 *
 * Supported operators:
 *   +, -, *, /
 *
 * Example 1:
 * Input:
 *   "23+"
 *
 * Output:
 *   5
 *
 * Explanation:
 *   2 + 3 = 5
 *
 * Example 2:
 * Input:
 *   "231*+"
 *
 * Output:
 *   5
 *
 * Explanation:
 *   3 * 1 = 3
 *   2 + 3 = 5
 *
 * Example 3:
 * Input:
 *   "52+83-*"
 *
 * Output:
 *   35
 *
 * Explanation:
 *   5 + 2 = 7
 *   8 - 3 = 5
 *   7 * 5 = 35
 */
int PostFixEvaluation(char *string)
{
    int length = strlen(string) - 1;
    Stack *stack = NewStack(length);

    int result = 0;

    for (int i = 0; i < length; i++)
    {
        if (isdigit(string[i]))
        {
            Push(stack, string[i] - '0');
        }
        else
        {
            if (stack->size < 2)
            {
                return -1;
            }
            int right = Pop(stack);
            int left = Pop(stack);

            switch (string[i])
            {
            case '+': {
                result = left + right;
                break;
            };
            case '-': {
                result = left - right;
                break;
            }
            case '*': {
                result = left * right;
                break;
            }
            case '/': {
                result = left / right;
                break;
            }
            default: {
                return -1;
            }
            }
            Push(stack, result);
        }
    }

    if (stack->size == 1)
    {
        return Pop(stack);
    }

    return -1;
}

int main()
{
    char string[64];
    printf("Enter expression : ");
    fgets(string, 64, stdin);

    int result = PostFixEvaluation(string);
    printf("Result : %d\n", result);

    return 0;
}
