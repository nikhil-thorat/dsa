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
 * Deletes the given value from the BST.
 * Time complexity is O(log n).
 */
void Delete(BST *bst, int value)
{
    if (bst == NULL)
    {
        return;
    }

    Node *toDelete = NULL;
    Node *parent = NULL;
    Node *current = bst->root;

    while (current != NULL)
    {
        if (current->data == value)
        {
            toDelete = current;
            break;
        }
        if (current->data > value)
        {
            parent = current;
            current = current->left_node;
        }
        else
        {
            parent = current;
            current = current->right_node;
        }
    }

    if (toDelete == NULL)
    {
        return;
    }

    if (toDelete->left_node == NULL && toDelete->right_node == NULL)
    {
        if (parent->left_node == toDelete)
        {
            parent->left_node = NULL;
        }

        if (parent->right_node == toDelete)
        {
            parent->right_node = NULL;
        }
        free(toDelete);
        return;
    }

    if (toDelete->right_node == NULL && toDelete->left_node != NULL)
    {
        Node *left_tree = toDelete->left_node;
        if (parent->left_node == toDelete)
        {
            parent->left_node = left_tree;
        }

        if (parent->right_node == toDelete)
        {
            parent->right_node = left_tree;
        }
        free(toDelete);
        return;
    }

    if (toDelete->left_node == NULL && toDelete->right_node != NULL)
    {
        Node *right_tree = toDelete->right_node;
        if (parent->left_node == toDelete)
        {
            parent->left_node = right_tree;
        }

        if (parent->right_node == toDelete)
        {
            parent->right_node = right_tree;
        }
        free(toDelete);
        return;
    }

    parent = toDelete;
    current = toDelete->right_node;
    while (current->left_node != NULL)
    {
        parent = current;
        current = current->left_node;
    }

    toDelete->data = current->data;

    if (parent->left_node == current)
    {
        parent->left_node = current->right_node;
    }
    else
    {
        parent->right_node = current->right_node;
    }
    free(current);
};

/*
 * Searches the given key in the BST.
 * Returns 1 if found else 0.
 * Time complexity is O(log n).
 */
int Search(BST *bst, int value)
{
    Node *current = bst->root;
    while (current != NULL)
    {
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
            return 1;
        }
    }

    return 0;
}

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

int main()
{
    BST *bst = NewBST();
    Insert(bst, 6);
    Insert(bst, 4);
    Insert(bst, 9);
    Insert(bst, 2);
    Insert(bst, 5);
    Insert(bst, 8);
    Insert(bst, 10);
    Insert(bst, 1);
    Insert(bst, 3);
    Insert(bst, 7);

    PrintElements(bst, InorderTraversal);
    PrintElements(bst, PreorderTraversal);
    PrintElements(bst, PostorderTraversal);

    int value = 5;
    int result = Search(bst, value);
    if (result)
    {
        printf("%d Exists in BST\n", value);
    }
    else
    {
        printf("%d Does not exists in BST\n", value);
    }

    Delete(bst, 1);
    PrintElements(bst, InorderTraversal);

    Delete(bst, 8);
    PrintElements(bst, InorderTraversal);

    Delete(bst, 6);
    PrintElements(bst, InorderTraversal);

    return 0;
}
