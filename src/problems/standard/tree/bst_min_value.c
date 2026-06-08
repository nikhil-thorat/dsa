#include <stdio.h>
#include <stdlib.h>

/*
 * Represents BST Node.
 */
typedef struct Node Node;
typedef struct Node
{
    int data;
    Node *left_node;
    Node *right_node;
} Node;

/*
 * Creates a new Node with given
 * value and returns a pointer
 * to it.
 */
Node *NewNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left_node = NULL;
    node->right_node = NULL;

    return node;
};

/*
 * Represents BST type.
 */
typedef struct
{
    Node *root;
} BST;

/*
 * Creates a new BST and returns
 * a pointer to it.
 */
BST *NewBST()
{
    BST *bst = (BST *)malloc(sizeof(BST));
    bst->root = NULL;

    return bst;
}

/*
 * Returns 1 if BST is empty
 * else 0.
 */
int IsEmpty(BST *bst)
{
    return bst->root == NULL;
};

/*
 * Inserts a given value into the
 * BST.
 * Time complexity is O(log N).
 */
void Insert(BST *bst, int value)
{

    Node *new_node = NewNode(value);

    if (IsEmpty(bst))
    {
        bst->root = new_node;
        return;
    }

    Node *parent = NULL;
    Node *current = bst->root;

    while (current != NULL)
    {
        parent = current;
        if (current->data > value)
        {
            current = current->left_node;
        }
        else if (current->data < value)
        {
            current = current->right_node;
        }
        else
        {
            free(new_node);
            return;
        }
    }

    if (value < parent->data)
    {
        parent->left_node = new_node;
    }
    else
    {
        parent->right_node = new_node;
    }
};

/*
 * Inorder Traversal
 */
void InorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    InorderTraversal(node->left_node);
    printf("%d ", node->data);
    InorderTraversal(node->right_node);
}

/*
 * Preorder Traversal
 */
void PreorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d ", node->data);
    PreorderTraversal(node->left_node);
    PreorderTraversal(node->right_node);
}

/*
 * Postorder Traversal
 */
void PostorderTraversal(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    PostorderTraversal(node->left_node);
    PostorderTraversal(node->right_node);
    printf("%d ", node->data);
}

/*
 * Print the elements of BST
 */
void PrintElements(BST *bst, void (*Method)(Node *))
{
    Method(bst->root);
    printf("\n");
};

/*
 * Problem Statement
 * Given the root of a Binary Search Tree (BST),
 * find and return the minimum value stored in
 * the tree.
 *
 * Note:
 * In a BST, all values in the left subtree are
 * smaller than the value of the current node,
 * and all values in the right subtree are
 * greater.
 *
 * Example:
 * Input:
 *
 *         10
 *        /  \
 *       5    15
 *      / \
 *     2   7
 *
 * Output:
 *   2
 *
 * Explanation:
 * The minimum value in a BST is found by
 * traversing to the leftmost node.
 */
int MinValue(BST *bst)
{
    Node *current = bst->root;
    while (current->left_node)
    {
        current = current->left_node;
    }

    return current->data;
}

int main()
{
    BST *bst = NewBST();
    Insert(bst, 10);
    Insert(bst, 5);
    Insert(bst, 15);
    Insert(bst, 2);
    Insert(bst, 7);
    PrintElements(bst, PreorderTraversal);

    int min_value = MinValue(bst);
    printf("Min Value : %d\n", min_value);

    Insert(bst, 1);
    PrintElements(bst, PreorderTraversal);

    min_value = MinValue(bst);
    printf("Min Value : %d\n", min_value);

    return 0;
}
