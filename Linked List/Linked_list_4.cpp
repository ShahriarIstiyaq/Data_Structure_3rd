/*----------------------Deletion in a Linked List----------------*/
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

    ptr->next = NULL; // At last nodes link filed we store null to indicate end of the list.
}

void give_output()
{
    // here at first ptr holds the address which is in the head.
    struct node *ptr = head;

    cout << "Data of the nodes are:\n";
    while (ptr != NULL)
    {
        // cnt++;
        cout << ptr->data << " ";
        ptr = ptr->next; // Updating pointer to point to the next node.
    }
}

void Delete()
{
    int pos;
    cout << "Please enter the position of the node you want to delete: ";
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid index!!" << endl;
        return;
    }

    if (pos == 1)
    {
        struct node *ptr = head; // Now the ptr is pointing to the 1st node whose address was in head.
        head = ptr->next;        // In ptr->next the address of 2nd node was stored. So, now head is pointing towards the 2nd node.
        free(ptr);               // Release the space allocated for 1st node.
    }
    else
    {
        struct node *p = head; // previous node
        struct node *c = head; // current node

        for (int i = 1; i < pos; i++)
        {
            p = c;
            c = c->next;
        }
        p->next = c->next;
        free(c);
        /*Suppose the linkded list is : 1  2  3  4  5
                                        10 20 30 40 50
        Now when we want to delete the 4th node.
        Then inside the loop at the end Pointer P will be pointing towards the previous node at which pointer C was pointing ,which is 3rd node.
        Then at the end when C = C->next will be exicuted then C will point from 3rd node to C->next(which was holding the address of 4th node.), Meaning now C is pointing at 4th node.
        And finally after the loop when P->next = C->next is exicuted , then (3rd node)P->next will hold the address of 5th node which was in (4th node)C->next
        Then at last we free the memory allocated for 4th node (pointer C) */
    }

    n--;

    cout << endl;
    cout << "After Deletion- ";
    give_output();
}

int main()
{

    cout << "Enter number of elements: ";
    cin >> n;
    cout << endl;

    take_input();
    give_output();
    cout << endl;

    Delete();

    return 0;
}