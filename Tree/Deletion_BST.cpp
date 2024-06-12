#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree *left;  // left child of a node.
    tree *right; // right child of a node.
};
tree *root; // root node of the tree.

// Function for Instering in BST:
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
    {
        // when parent node data is greater than insert item to left child of the current parent node.
        par->left = newNode;
    }
    else
    {
        // When parent node data is equal or less than insert item to right child of the current parent node.
        par->right = newNode;
    }
}

// Function for finding the last node inorder with Deleted node:
tree *findMin(tree *node)
{
    tree *current = node; // here current node is the right child of the node that is to be deleted.

    while (current && current->left != NULL) // This find the last leaf on the left subtree of the right child.
        current = current->left;

    return current;
}

// Function for Searching in BST:
void Delete(int item)
{
    tree *parent = NULL;  // parent node.
    tree *current = root; // current node.

    // Searching the node that is to be deleted:
    while (current != NULL && current->data != item)
    {
        parent = current;

        if (current->data > item)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
    {
        cout << "Item not found in the BST!!";
        return;
    }

    // Case 1: node to be deleted has no children:
    if (current->left == NULL && current->right == NULL)
    {
        cout << "The node has no children!" << endl;

        if (current != root)
        { // current node is not the Root
            // Checking which child of the parent does the deleting node belongs to and removing it from there
            if (parent->left == current)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;

        free(current);
    }

    // Case2: node to be deleted has one child:
    else if (current->left == NULL || current->right == NULL)
    {
        cout << "The node has one child!" << endl;

        tree *child = (current->left) ? current->left : current->right; // Finding which of the subtree the child of current node belongs to

        if (current != root)
        { // current node is not the Root
            // Replacing current node with its child
            if (parent->left == current)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;

        free(current);
    }

    // Case 3: node to be deleted has two children:
    else if (current->left && current->right)
    {
        cout << "The node has two children!" << endl;

        tree *successor = findMin(current->right);
        int value = successor->data;
        Delete(successor->data);
        current->data = value;
    }
}

// Function for The 3 triversal methode in BST:
void inOrder(tree *ptr) // InOrder -> LPR
{                       // This recursive call will go on until it finds the a leaf with no left child.
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

// Function for Displaying data in BST:
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

// Menu Function:
int menu()
{
    int n;

    printf("\n\nMain Menu\n");
    printf("1. Insert\n");
    printf("2. Delete item.\n");
    printf("3. Display\n");
    printf("4. Exit\n\n");
    printf("Enter Choice(1-4): ");
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
        {
            cout << "Enter the item you want to delete: ";
            cin >> item;
            Delete(item);
            cout << "The item has been deleted from the BST!!" << endl;
        }
        if (choice == 3)
            Display();

        if (choice == 4)
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
