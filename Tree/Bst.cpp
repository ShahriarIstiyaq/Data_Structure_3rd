/* Implementation of binary search tree using LL and traversal - Inorder,preorder,postorder.*/
#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree *left;  // left child of a node.
    tree *right; // right child of a node.
};
tree *root; // root node of the tree.

void insert(int item)
{
    tree *ptr = root; // pointer to find location of item
    tree *par = NULL; // pointer to save the location of parent node of item.

    // Creating a new node:
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->data = item;
    newNode->left = newNode->right = NULL;

    while (ptr != NULL)
    {
        par = ptr; // setting parent node to root.

        if (ptr->data > item)
            ptr = ptr->left; // when parent node data is greater than item move to left child
        else
            ptr = ptr->right; // when parent node data is equal or less than item move to right child
    }

    if (par == NULL) // When the tree is empty.
        root = newNode;
    else if (par->data > item)
        par->left = newNode; // when parent node data is greater than insert item to left child of the current parent node.
    else
        par->right = newNode; // When parent node data is equal or less than insert item to right child of the current parent node.
}

void inOrder(tree *ptr) // InOrder -> LPR
{
    // This recursive call will go on until it finds the a leaf with no left child.
    if (ptr != NULL)
    {
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
}

void preOrder(tree *ptr) // PreOrder -> PLR
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void postOrder(tree *ptr) // PostOrder -> LRP
{
    if (ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " ";
    }
}

void Display()
{
    if (root)
    {
        printf("\nTraverse Tree INorder\n");
        inOrder(root);
        printf("\nTraverse Tree PREorder\n");
        preOrder(root);
        printf("\nTraverse Tree POSTorder\n");
        postOrder(root);
    }
    else
        printf("\nBST IS NULL\n");
}

int menu()
{
    int n;

    printf("\n\nMain Menu\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Exit\n\n");
    printf("Enter Choice(1-3): ");
    scanf("%d", &n);
    printf("\n");
    return n;
}

int main()
{
    tree *T;
    root = NULL;
    int choice = menu();
    int item;

    do
    {

        if (choice == 1)
        {
            cout << "Enter the value you want to insert in BST: ";
            cin >> item;
            insert(item);
        }

        if (choice == 2)
            Display();

        if (choice == 3)
        {
            cout << "<----End of operation--->" << endl;
            break;
        }
        if (choice > 3)
            cout << "\nWrong Choice\n";

        choice = menu();
    } while (1);

    return 0;
}