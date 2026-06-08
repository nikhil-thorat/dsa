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
    char *elements;
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
    stack->elements = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

/*
 * Pushes the given value onto
 * the Stack.
 * Time complexity is O(1).
 */
void Push(Stack *stack, char value)
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
char Top(Stack *stack)
{
    return stack->elements[stack->size - 1];
}

/*
 * Prints the elements of
 * the Stack.
 */
void PrintElements(Stack *stack)
{
    for (int i = 0; i < stack->size; i++)
    {
        printf("%c ", stack->elements[i]);
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

char OpeningToClosing(char bracket)
{
    if (bracket == '(')
    {
        return ')';
    }
    else if (bracket == '[')
    {
        return ']';
    }
    else if (bracket == '{')
    {
        return '}';
    }

    return ' ';
}

/*
 * Problem Statement
 * Given a string containing only opening and
 * closing brackets '()', '{}', and '[]',
 * determine whether the brackets are balanced.
 *
 * A string is considered valid if:
 *   1. Every opening bracket has a corresponding
 *      closing bracket of the same type.
 *   2. Brackets are closed in the correct order.
 *   3. Every closing bracket has a matching
 *      opening bracket.
 *
 * Return 1 if the string is valid, otherwise
 * return 0.
 *
 * Example 1:
 * Input:
 *   "()"
 *
 * Output:
 *   1
 *
 * Example 2:
 * Input:
 *   "()[]{}"
 *
 * Output:
 *   1
 *
 * Example 3:
 * Input:
 *   "([{}])"
 *
 * Output:
 *   1
 *
 * Example 4:
 * Input:
 *   "([)]"
 *
 * Output:
 *   0
 *
 * Example 5:
 * Input:
 *   "((("
 *
 * Output:
 *   0
 */
int ValidParenthesis(char *string)
{
    int length = strlen(string) - 1;
    Stack *stack = NewStack(length);

    for (int i = 0; i < length; i++)
    {
        if (string[i] == '(' || string[i] == '[' || string[i] == '{')
        {
            Push(stack, OpeningToClosing(string[i]));
        }
        else
        {
            if (stack->size == 0)
            {
                return 0;
            }

            if (Top(stack) != string[i])
            {
                break;
            }

            Pop(stack);
        }
        PrintElements(stack);
    }

    return stack->size == 0;
}

int main()
{
    char string[64];
    printf("Enter string : ");
    fgets(string, 64, stdin);

    int is_valid = ValidParenthesis(string);
    if (is_valid)
    {
        puts("String is Valid");
    }
    else
    {
        puts("String is not Valid");
    }

    return 0;
}
