/*----------------------Search in a Linked List----------------*/
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
    cout << "Data of the nodes are:\n";
    while (ptr != NULL)
    {
        // cnt++;
        cout << ptr->data << " ";
        ptr = ptr->next; // Updating pointer to point to the next node.
    }
}

void search(node *start)
{
    int item;                // The item to search.
    struct node *loc = NULL; // The location of the item.
    struct node *ptr = start;
    int cnt = 0; // Number of nodes.

    cout << "Enter the element to search: ";
    cin >> item;

    while (ptr != NULL)
    {
        cnt++;

        if (item > ptr->data)
            ptr = ptr->next;

        else if (item == ptr->data)
        {
            loc = ptr;
            cout << "The item found at location " << loc << " and it id situated at node " << cnt << endl;
            return;
        }
    }

    cout << "The item is not found in the linked list!!\n";
}

int main()
{
    struct node *head, *ptr;
    head = (struct node *)malloc(sizeof(struct node));

    cout << "Enter number of elements: ";
    cin >> n;
    cout << endl;

    take_input(head);
    give_output(head);
    cout << endl;

    search(head);
    return 0;
}