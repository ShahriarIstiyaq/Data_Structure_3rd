/*----------------------Implementation of Priority Queue using Array----------------*/
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100
struct Queue
{
    int data;
    int priority;
};

Queue q[MAX_SIZE]; // array of Queue.
int size = 0;

bool isEmpty()
{
    return size == 0;
}

bool isFull()
{
    return size == MAX_SIZE;
}

// Peek of queue:
int peek()
{
    int high = INT_MIN;
    int hidx = -1;

    // Finding the element with highest priority:
    for (int i = 0; i < size; i++)
    {
        if (high == q[i].priority && hidx > -1 && q[hidx].data < q[i].data)
        {
            // If priority is same we have to chose the element with highest value.
            high = q[i].priority;
            hidx = i;
        }

        else if (high < q[i].priority)
        {
            high = q[i].priority;
            hidx = i;
        }
    }

    return hidx; // return highest priority index.
}

// Enqueue:(Insertion)
void enqueue(int item, int pr)
{
    if (isFull())
    {
        cout << "The Queue is full!!" << endl;
        return;
    }

    size++; // increment of size.
    q[size - 1].data = item;
    q[size - 1].priority = pr;
    cout << "\nThe item " << item << " is successfully Enqueued" << endl;
}

// Dequeue:(Deletion)
void dequeue()
{
    if (isEmpty())
    {
        cout << "The Queue is empty!!" << endl;
        return;
    }

    int hidx = peek();
    cout << "\nThe item " << q[hidx].data << " is successfully dequeued" << endl;
    // Shifting the elements:
    for (int i = hidx; i < size; i++)
        q[i] = q[i + 1];

    size--;
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty!!" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
        cout << q[i].data << " ";
    cout << endl;
}

int main()
{
    int choice, item, priority;
    do
    {
        printf("\n-----------Main Menu-------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. GetPeek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:
            cout << "Enter value to enqueue: ";
            cin >> item;
            cout << "Enter priority of that value: ";
            cin >> priority;
            enqueue(item, priority);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << endl;
            cout << "The peek of the queue is " << q[peek()].data << endl;
            break;

        case 5:
            printf("<-End operation->\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}