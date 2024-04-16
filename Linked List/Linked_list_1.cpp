/*----------------------Implementation of Linked List----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}; // node created.

void take_input(struct node *ptr, int n)
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
    while (ptr != NULL)
    {
        cnt++;
        cout << "Data of the node" << cnt << " is: " << ptr->data << endl;
        ptr = ptr->next; // Updating pointer to point to the next node.
    }
}

int main()
{
    struct node *head, *ptr;                           // ptr is a temp pointer to use in various perpose.
    head = (struct node *)malloc(sizeof(struct node)); // memory allocation to the head.
    ptr = head;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << endl;

    take_input(head, n);
    cout << endl;
    give_output(head);

    return 0;
}
