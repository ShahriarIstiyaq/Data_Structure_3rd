#include <bits/stdc++.h>
using namespace std;

struct bst
{
    int data;
    bst *left;
    bst *right;
};

void insert(int item, bst *&root) // Passing the root address by reference, so that it could be modified.
{

    // New node:
    bst *New_node = (bst *)malloc(sizeof(bst));
    New_node->data = item;
    New_node->left = New_node->right = NULL;

    if (root == NULL)
        root = New_node;

    else
    {
        bst *ptr = root;
        bst *par; // parent node.

        while (ptr != NULL)
        {
            par = ptr;
            if (item < ptr->data)
                ptr = ptr->left;

            else
                ptr = ptr->right;
        }

        if (item < par->data)
            par->left = New_node;

        else
            par->right = New_node;
    }
}

void preOrder(bst *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void inOrder(bst *ptr)
{
    if (ptr != NULL)
    {
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
}

void postOrder(bst *ptr)
{
    if (ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " ";
    }
}

void display(bst *root)
{
    cout << "pre: ";
    preOrder(root);
    cout << endl;

    cout << "In: ";
    inOrder(root);
    cout << endl;

    cout << "post: ";
    postOrder(root);
    cout << endl;
}

int main()
{
    bst *root = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Insert item: ";
        int x;
        cin >> x;
        insert(x, root);
    }

    display(root);

    return 0;
}