/*----------------------Implementation of Circular Linked List----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}; // node created.

struct node *head = (struct node *)malloc(sizeof(struct node));
int n; // number of nodes

void take_input()
{
    // here at first ptr holds the address which is in the head.
    struct node *ptr = head;

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

    ptr->next = head; // At last nodes link filed we store The pointer to the head node(1st node).
}

void give_output()
{
    // here at first ptr holds the address which is in the head.
    struct node *ptr = head;
    int cnt = 0;

    cout << "Data of the nodes are:\n";
    do
    {
        cnt++;
        cout << "Data of the node" << cnt << " is: " << ptr->data << endl;
        ptr = ptr->next; // Updating pointer to point to the next node.
    } while (ptr != head);
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