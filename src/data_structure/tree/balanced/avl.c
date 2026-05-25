#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

/*
 * Represents AVLTree Node.
 */
typedef struct Node Node;
typedef struct Node
{
    int data;
    int height;
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
    node->height = 1;
    node->left_node = NULL;
    node->right_node = NULL;

    return node;
};

/*
 * Represents AVLTree type.
 */
typedef struct
{
    Node *root;
} AVLTree;

/*
 * Creates a new AVLTree and returns
 * a pointer to it.
 */
AVLTree *NewAVLTree()
{
    AVLTree *avl_tree = (AVLTree *)malloc(sizeof(AVLTree));
    avl_tree->root = NULL;

    return avl_tree;
}

/*
 * Returns 1 if AVLTree is empty
 * else 0.
 */
int IsEmpty(AVLTree *avl_tree)
{
    return avl_tree->root == NULL;
};

/*
 * Returns the height of the Node.
 */
int Height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return node->height;
}

/*
 * Returns the Balance factor of the Node.
 */
int BalanceFactor(Node *node)
{

    if (node == NULL)
    {
        return 0;
    }

    return Height(node->left_node) - Height(node->right_node);
};

/*
 * Max function
 */
int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

/*
 * Left Rotation
 */
Node *LeftRotate(Node *node)
{
    Node *right_subtree = node->right_node;
    Node *left_of_right_subtree = right_subtree->left_node;

    right_subtree->left_node = node;
    node->right_node = left_of_right_subtree;

    node->height = Max(Height(node->left_node), Height(node->right_node)) + 1;
    right_subtree->height = Max(Height(right_subtree->left_node), Height(right_subtree->right_node)) + 1;

    return right_subtree;
}

/*
 * Right Rotation
 */
Node *RightRotate(Node *node)
{
    Node *left_subtree = node->left_node;
    Node *right_of_left_subtree = left_subtree->right_node;

    left_subtree->right_node = node;
    node->left_node = right_of_left_subtree;

    node->height = Max(Height(node->left_node), Height(node->right_node)) + 1;
    left_subtree->height = Max(Height(left_subtree->left_node), Height(left_subtree->right_node)) + 1;

    return left_subtree;
}

/*
 * LeftRight Rotation
 */
Node *LeftRightRotate(Node *node)
{
    node->left_node = LeftRotate(node->left_node);
    return RightRotate(node);
}

/*
 * RightLeft Rotation
 */
Node *RightLeftRotate(Node *node)
{
    node->right_node = RightRotate(node->right_node);
    return LeftRotate(node);
}

/*
 * Insertion helper function.
 */
Node *InsertNode(Node *node, int value)
{
    if (node == NULL)
    {
        return NewNode(value);
    }

    if (value < node->data)
    {
        node->left_node = InsertNode(node->left_node, value);
    }
    else if (value > node->data)
    {
        node->right_node = InsertNode(node->right_node, value);
    }
    else
    {
        return node;
    }

    node->height = 1 + Max(Height(node->left_node), Height(node->right_node));
    int balance_factor = BalanceFactor(node);

    if (balance_factor < -1 && value > node->right_node->data)
    {
        return LeftRotate(node);
    }

    if (balance_factor > 1 && value < node->left_node->data)
    {
        return RightRotate(node);
    }

    if (balance_factor > 1 && value > node->left_node->data)
    {
        return LeftRightRotate(node);
    }

    if (balance_factor < -1 && value < node->right_node->data)
    {
        return RightLeftRotate(node);
    }

    return node;
}

/*
 * Inserts a given value into the
 * AVLTree.
 * Time complexity is O(log N).
 */
void Insert(AVLTree *avl_tree, int value)
{
    avl_tree->root = InsertNode(avl_tree->root, value);
};

/*
 * Returns a Node with the mimimum value
 * in the given subtree.
 */
Node *MinNode(Node *node)
{
    Node *current = node;
    while (current->left_node != NULL)
    {
        current = current->left_node;
    }

    return current;
};

/*
 * Deletion helper function.
 */
void *DeleteNode(Node *node, int value)
{

    if (node == NULL)
    {
        return NULL;
    }

    if (value < node->data)
    {
        node->left_node = DeleteNode(node->left_node, value);
    }
    else if (value > node->data)
    {
        node->right_node = DeleteNode(node->right_node, value);
    }
    else
    {
        if (node->left_node == NULL && node->right_node == NULL)
        {
            free(node);
            return NULL;
        }

        if (node->left_node == NULL)
        {
            Node *temp = node->right_node;
            free(node);
            return temp;
        }

        if (node->right_node == NULL)
        {
            Node *temp = node->left_node;
            free(node);
            return temp;
        }

        Node *successor = MinNode(node->right_node);
        node->data = successor->data;
        node->right_node = DeleteNode(node->right_node, successor->data);
    }

    node->height = 1 + Max(Height(node->left_node), Height(node->right_node));
    int balance_factor = BalanceFactor(node);

    if (balance_factor < -1 && value > node->right_node->data)
    {
        return LeftRotate(node);
    }

    if (balance_factor > 1 && value < node->left_node->data)
    {
        return RightRotate(node);
    }

    if (balance_factor > 1 && value > node->left_node->data)
    {
        return LeftRightRotate(node);
    }

    if (balance_factor < -1 && value < node->right_node->data)
    {
        return RightLeftRotate(node);
    }

    return node;
};

/*
 * Deletes the given value from the AVLTree.
 * Time complexity is O(log n).
 */
void Delete(AVLTree *avl_tree, int value)
{
    avl_tree->root = DeleteNode(avl_tree->root, value);
};

/*
 * Searches the given key in the AVLTree.
 * Returns 1 if found else 0.
 * Time complexity is O(log n).
 */
int Search(AVLTree *avl_tree, int value)
{
    Node *current = avl_tree->root;
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
 * Print the elements of AVLTree
 */
void PrintElements(AVLTree *avl_tree, void (*Method)(Node *))
{
    Method(avl_tree->root);
    printf("\n");
};

int main()
{
    AVLTree *avl_tree = NewAVLTree();
    Insert(avl_tree, 10);
    Insert(avl_tree, 20);
    Insert(avl_tree, 30);
    Insert(avl_tree, 40);
    Insert(avl_tree, 50);
    PrintElements(avl_tree, PreorderTraversal);

    Insert(avl_tree, 5);
    PrintElements(avl_tree, PreorderTraversal);

    Delete(avl_tree, 5);
    PrintElements(avl_tree, PreorderTraversal);

    return 0;
}
