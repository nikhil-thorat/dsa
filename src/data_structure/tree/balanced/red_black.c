#include <stdio.h>
#include <stdlib.h>

#define RED 'r'
#define BLACK 'b'

/*
 * Represents RedBlackTree Node.
 */
typedef struct Node Node;
typedef struct Node
{
    int data;
    char color;
    Node *left_node;
    Node *right_node;
    Node *parent_node;
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
    node->color = RED;
    node->left_node = NULL;
    node->right_node = NULL;
    node->parent_node = NULL;

    return node;
};

/*
 * Represents RedBlackTree type.
 */
typedef struct
{
    Node *root;
} RBTree;

/*
 * Creates a new RedBlackTree and returns
 * a pointer to it.
 */
RBTree *NewRBTree()
{
    RBTree *rb_tree = (RBTree *)malloc(sizeof(RBTree));
    rb_tree->root = NULL;

    return rb_tree;
}

/*
 * Left Rotation
 */
void LeftRotate(RBTree *rb_tree, Node *node)
{
    Node *right_of_node = node->right_node;
    node->right_node = right_of_node->left_node;

    if (right_of_node->left_node != NULL)
    {
        right_of_node->left_node->parent_node = node;
    }

    right_of_node->parent_node = node->parent_node;

    if (node->parent_node == NULL)
    {
        rb_tree->root = right_of_node;
    }
    else if (node == node->parent_node->left_node)
    {
        node->parent_node->left_node = right_of_node;
    }
    else
    {
        node->parent_node->right_node = right_of_node;
    }

    right_of_node->left_node = node;
    node->parent_node = right_of_node;
}

/*
 * Right Rotation
 */
void RightRotate(RBTree *rb_tree, Node *node)
{
    Node *left_of_node = node->left_node;
    node->left_node = left_of_node->right_node;

    if (left_of_node->right_node != NULL)
    {
        left_of_node->right_node->parent_node = node;
    }

    left_of_node->parent_node = node->parent_node;

    if (node->parent_node == NULL)
    {
        rb_tree->root = left_of_node;
    }
    else if (node == node->parent_node->right_node)
    {
        node->parent_node->right_node = left_of_node;
    }
    else
    {
        node->parent_node->left_node = left_of_node;
    }

    left_of_node->right_node = node;
    node->parent_node = left_of_node;
}

/*
 * Balances the RedBlackTree.
 */
void Balance(RBTree *rb_tree, Node *node)
{
    while (node->parent_node && node->parent_node->color == RED)
    {
        if (node->parent_node == node->parent_node->parent_node->left_node)
        {
            Node *node_uncle = node->parent_node->parent_node->right_node;

            if (node_uncle != NULL && node_uncle->color == RED)
            {
                node->parent_node->color = BLACK;
                node->parent_node->parent_node->color = RED;
                node_uncle->color = BLACK;
                node = node->parent_node->parent_node;
            }
            else
            {
                if (node == node->parent_node->right_node)
                {
                    node = node->parent_node;
                    LeftRotate(rb_tree, node);
                }

                node->parent_node->color = BLACK;
                node->parent_node->parent_node->color = RED;
                RightRotate(rb_tree, node->parent_node->parent_node);
            }
        }
        else
        {
            Node *node_uncle = node->parent_node->parent_node->left_node;

            if (node_uncle != NULL && node_uncle->color == RED)
            {
                node->parent_node->color = BLACK;
                node->parent_node->parent_node->color = RED;
                node_uncle->color = BLACK;
                node = node->parent_node->parent_node;
            }
            else
            {
                if (node == node->parent_node->left_node)
                {
                    node = node->parent_node;
                    RightRotate(rb_tree, node);
                }

                node->parent_node->color = BLACK;
                node->parent_node->parent_node->color = RED;
                LeftRotate(rb_tree, node->parent_node->parent_node);
            }
        }

        if (node == rb_tree->root)
        {
            break;
        }
    }

    rb_tree->root->color = BLACK;
}

/*
 * Inserts a given value into the
 * RedBlackTree.
 * Time complexity is O(log N).
 */
void Insert(RBTree *rb_tree, int value)
{
    Node *new_node = NewNode(value);

    Node *parent = NULL;
    Node *current = rb_tree->root;

    while (current != NULL)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left_node;
        }
        else
        {
            current = current->right_node;
        }
    }

    new_node->parent_node = parent;

    if (parent == NULL)
    {
        rb_tree->root = new_node;
    }
    else if (new_node->data < parent->data)
    {
        parent->left_node = new_node;
    }
    else
    {
        parent->right_node = new_node;
    }

    Balance(rb_tree, new_node);
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
 * Print the elements of RedBlackTree
 */
void PrintElements(RBTree *rb_tree, void (*Method)(Node *))
{
    Method(rb_tree->root);
    printf("\n");
};

int main()
{
    RBTree *rb_tree = NewRBTree();

    Insert(rb_tree, 10);
    Insert(rb_tree, 20);
    Insert(rb_tree, 30);
    Insert(rb_tree, 40);
    Insert(rb_tree, 50);
    PrintElements(rb_tree, PreorderTraversal);

    return 0;
}
