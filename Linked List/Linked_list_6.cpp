/*----------------------Implementation of Double Linked List----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}; // node created.

struct node *head = (struct node *)malloc(sizeof(struct node));
int n; // number of nodes

void take_input()
{
    struct node *p1 = NULL; // previous node
    struct node *p2;        // new node

    for (int i = 1; i <= n; i++)
    {
        p2 = (struct node *)malloc(sizeof(struct node)); // allocating memory for new nodes.

        cout << "Input data: ";
        cin >> p2->data;

        p2->prev = p1;   // new nodes "prev" will hold the address of previous node.
        p2->next = NULL; // new nodes "next" initializes as null.

        if (p1 != NULL)
            p1->next = p2;

        else
            head = p2; // If previous node is null that means it is the first node.

        p1 = p2; // Updating previous node.
    }
}

void give_output()
{
    // here at first ptr holds the address which is in the head.
    struct node *ptr = head;
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

    cout << "Enter number of elements: ";
    cin >> n;
    cout << endl;

    take_input();
    cout << endl;
    give_output();

    return 0;
}