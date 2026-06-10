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
 * Helper function
 */
void Swap(Node *root)
{
    if (!root)
    {
        return;
    }

    Node *right = root->right_node;
    Node *left = root->left_node;

    if (right)
    {
        Swap(right);
    }

    if (left)
    {
        Swap(left);
    }

    root->left_node = right;
    root->right_node = left;
}

/*
 * Problem Statement
 * Given the root of a Binary Search Tree (BST),
 * create and return the mirror image of the tree.
 *
 * The mirror image of a tree is obtained by
 * swapping the left and right child of every
 * node in the tree.
 *
 * Example:
 * Input:
 *
 *         4
 *        / \
 *       2   6
 *      / \ / \
 *     1  3 5  7
 *
 * Output:
 *
 *         4
 *        / \
 *       6   2
 *      / \ / \
 *     7  5 3  1
 *
 * Explanation:
 * For every node, the left and right
 * subtrees are exchanged.
 */
void Mirrored(BST *bst)
{
    Swap(bst->root);
}

int main()
{
    BST *bst = NewBST();
    Insert(bst, 4);
    Insert(bst, 2);
    Insert(bst, 6);
    Insert(bst, 1);
    Insert(bst, 3);
    Insert(bst, 5);
    Insert(bst, 7);
    PrintElements(bst, PreorderTraversal);

    Mirrored(bst);
    PrintElements(bst, PreorderTraversal);
    Mirrored(bst);

    Insert(bst, 0);
    Insert(bst, 10);
    PrintElements(bst, PreorderTraversal);

    Mirrored(bst);
    PrintElements(bst, PreorderTraversal);

    return 0;
}
