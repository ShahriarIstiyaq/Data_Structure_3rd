/*----------------------Insertion in a Linked List----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}; // node created.

int n; // number of nodes

void take_input(struct node *ptr)
{
    // here at first ptr holds the address which is in the head.

    for (int i = 1; i <= n; i++)
    {
        cout << "Input data: ";
        cin >> ptr->data;
        if (i != n)
        {
            ptr->next = (struct node *)malloc(sizeof(struct node)); // allocating memory for the next node.
            ptr = ptr->next;                                        // Updating pointer to point to the next node.
        }
    }

    ptr->next = NULL; // At last nodes link filed we store null to indicate end of the list.
}

void give_output(struct node *ptr)
{
    // here at first ptr holds the address which is in the head.
    int cnt = 0;
    cout << "Data of the nodes are:\n";
    while (ptr != NULL)
    {
        // cnt++;
        cout << ptr->data << " ";
        ptr = ptr->next; // Updating pointer to point to the next node.
    }
}

void insert(struct node *head)
{
    int item, pos;
    cout << "Please enter your data: ";
    cin >> item;

    cout << "Plase enter insertion position: ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid index!!" << endl;
        return;
    }

    // Creating a new node.
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;

    // Linking process:

    if (pos == 1) // At the beginning of the list.
    {
        newnode->next = head;
        head = newnode;
    }

    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node)); // Temporary pointer for traversal.
        ptr = head;

        for (int i = 1; i < pos - 1; i++) // This loop will run till it finds the previous node of given position.
            ptr = ptr->next;

        //  Linking process:
        newnode->next = ptr->next;
        ptr->next = newnode;

        /*Now ptr is pointing to the node which is currently in the insertion postion.We have to break the link and then join with the new node.
        suppose we have : 3  4  5
                          10 20 30
        we have to insert the new node in 4th position. Then ptr is in the 3rd node.
        Then ptr->next is holdin the address of the current 4th node.
        when we wrote newnode->next = ptr->next , now the newnode is also pointing to the current 4th node.
        But when we wrote ptr->next = newnode, it is now pointing to the new node,
        and it looks like this: 3  4  5  6
                                10 15 20 30
        */
    }

    n++; // increasing the element count.
}

int main()
{
    struct node *head, *ptr;                           // ptr is a temp pointer to use in various perpose.
    head = (struct node *)malloc(sizeof(struct node)); // memory allocation to the head.
    ptr = head;

    cout << "Enter number of elements: ";
    cin >> n;
    cout << endl;

    take_input(head);
    give_output(head);

    cout << endl;
    insert(head);
    cout << endl;
    give_output(head);

    return 0;
}
