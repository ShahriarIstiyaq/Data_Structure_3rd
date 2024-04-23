/*----------------------Implementation of Queue using static array----------------*/
#include <bits/stdc++.h>
using namespace std;

const int capacity = 100; // max size of the queue
int Queue[capacity];
int front = 0;
int size = 0;
int rare = -1;

// Method to see if queue is full(when size == capacity)
int isFull()
{
    return (size == capacity); // will return 1 if it's true.
}

// Method to see if queue is empty(when size == 0)
int isEmpty()
{
    return (size == 0);
}

// Enqueue:(changes size and rare end)
void enqueue(int item)
{
    if (isFull())
    {
        cout << "The Queue is full!!" << endl;
        return;
    }

    rare++;
    Queue[rare] = item; // inserting element at rare index.
    size++;             // increasing the size.

    cout << "The item " << item << " is successfully enqueued to queue." << endl;
}

// Dequeue:(changes size and front end)
void dequeue()
{
    if (isEmpty())
    {
        cout << "The queue is empty!!" << endl;
        return;
    }

    int item = Queue[front];
    front++;

    size--;

    cout << "The item " << item << " is successfully dequeued" << endl;
}

// Display:
void display()
{
    if (isEmpty())
    {
        cout << "The queue is empty!!" << endl;
        return;
    }

    cout << "Queue elements: " << endl;
    for (int i = front; i <= rare; i++)
        cout << Queue[i] << " ";

    /*Front is always index of first element.
    Rare is always index of (size -1)*/
    cout << endl;
}

// Method to get the front of the queue:
int Front()
{
    if (isEmpty())
        return INT_MIN;

    return Queue[front];
}

// Method to get the rare of the queue:
int Rare()
{
    if (isEmpty())
        return INT_MIN;

    return Queue[rare];
}

int main()
{
    // Initially queue:
    cout << "Initial state of the queue->" << endl;
    display();
    cout << endl;

    // Insertion in the queue:
    enqueue(10);
    enqueue(20);
    enqueue(50);
    display();

    // Front and Rare ends of the queue:
    cout << endl;
    cout << "The front of the queue is " << Front() << endl;
    cout << "The rare of the queue is " << Rare() << endl;
    cout << endl;

    // Deletion in the queue:
    dequeue();
    display();

    return 0;
}