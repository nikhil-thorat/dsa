#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Problem Statement
 * Given a string, reverse its characters
 * using a stack data structure.
 *
 * Example:
 * Input:
 *   "Hello"
 *
 * Output:
 *   "olleH"
 *
 * Explanation:
 * Push each character of the string onto
 * the stack, then pop the characters back
 * to obtain the reversed string.
 */

/*
 * Stack type.
 */
typedef struct
{
    size_t capacity;
    int top;
    char *elements;
} Stack;

Stack *NewStack(size_t capacity)
{
    Stack *stack = malloc(sizeof(Stack));

    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = malloc(sizeof(char) * stack->capacity);

    return stack;
}

/*
 * Push function
 */
void Push(Stack *stack, char ch)
{
    if (stack->top == stack->capacity)
    {
        puts("Stack is Full.");
        return;
    }

    stack->top++;
    stack->elements[stack->top] = ch;
}

/*
 * Pop function
 */
char Pop(Stack *stack)
{
    if (stack->top == -1)
    {
        puts("Stack is Empty.");
        return ' ';
    }

    char ch = stack->elements[stack->top];
    stack->top--;

    return ch;
}

/*
 * Reverse string function
 */
void ReverseString(char *string)
{
    int length = strlen(string) - 1;

    Stack *stack = NewStack(length);

    for (int i = 0; i < length; i++)
    {
        Push(stack, string[i]);
    }

    for (int i = 0; i < length; i++)
    {
        char ch = Pop(stack);
        string[i] = ch;
    }
}

int main()
{
    char string[64];
    printf("Enter a string : ");
    fgets(string, sizeof(string), stdin);

    printf("Before Reversing : %s\n", string);
    ReverseString(string);
    printf("After Reversing : %s\n", string);

    return 0;
}
