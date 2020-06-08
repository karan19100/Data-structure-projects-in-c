

#include <stdio.h>
#include <stdlib.h>

// the code is written & developed by karan shah 

Data structure to store a Binary Search Tree node
typedef struct Node {
    int data;
   struct Node *left, *right;
}Tree;

// Function to create a new binary tree node having given key
Tree* newNode(int key)
{
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

// Function to find Minimum value node in subtree rooted at node
Tree* MinValue(Tree* root)
{
    Tree* node=root;
    while (node->left!=NULL)
        node = node->left;

    return node;
}

// Function to find Maximum value node in subtree rooted at node
Tree* MaxValue(Tree* root)
{
    Tree* node=root;
    while (node->right!=NULL)
        node = node->right;

    return node;
}

// Recursive function to insert an key into BST
Tree* insert(Tree* root, int key)
{
    // if the root is null, create a new node an return it
    if (root == NULL)
        return newNode(key);

    // if given key is less than the root node, recurse for left subtree
    if (key < root->data)
        root->left = insert(root->left, key);

    // if given key is more than the root node, recurse for right subtree
    else
        root->right = insert(root->right, key);

    return root;
}

// Function to find a pair with given sum in given BST
int findPair(Tree* X, Tree* Y, int pair_sum, Tree* x, Tree* y)
{
    if (X == NULL || Y == NULL)
        return 0;

    // if current sum is less than the required sum, update x
    if (x->data + y->data < pair_sum)
    {
        if (findPair(X->left, Y, pair_sum, x, y))
            return 1;

        x = X;

        // if current sum is equal to the required sum,
        // print the pair and return 1
        if (x != y && x->data + y->data == pair_sum)
        {
            printf("Pair found (%d, %d)\n",x->data,y->data);
            return 1;
        }

        return findPair(X->right, Y, pair_sum, x, y);
    }

    // if current sum is more than the required sum, update y
    else
    {
        if (findPair(X, Y->right, pair_sum, x, y))
            return 1;

        y = Y;

        // if current sum is equal to the required sum,
        // print the pair and return 1
        if (x != y && x->data + y->data == pair_sum)
        {
            printf("Pair found (%d, %d)\n",x->data,y->data);

            return 1;
        }

        return findPair(X, Y->left, pair_sum, x, y);
    }
}

// main function
int main()
{
    Tree* root = NULL;

    int p;
    printf("Enter the elements in the list. Enter -1 to exit\n");
    for(;;){
      scanf("%d",&p);
      if(p==-1)
         break;
      root=insert(root,p);

    }
   Tree* x = MinValue(root);
    Tree* y = MaxValue(root);


    printf("Enter the sum you want\n");
    scanf("%d",&p);

    // find Minimum and Maximum key in binary search tree

    if (findPair(root, root,p, x, y)==0)
        printf("Pair does not exist");

    return 0;
}

