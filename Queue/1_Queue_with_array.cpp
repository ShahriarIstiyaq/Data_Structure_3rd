/*----------------------Implementation of Queue using array by dynamic memory allocation----------------*/

#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int front;    // front will store the index of first element.(Dequeue end)
    int rare;     // rare will store the index of last element(Enqueue end)
    int size;     // Current size of queue.
    int capacity; // Total capacity of queue.
    int *array;   // intiger pointer for dynamically allocated array.
};

struct Queue *createQueue(int cap) // Return type is a whole structre of Queue
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));

    q->capacity = cap; // total capacity of queue.
    q->front = 0;
    q->size = 0;
    q->rare = -1; // both of front and back are at 0 th index.

    q->array = (int *)malloc(q->capacity * sizeof(int));
    /*This will allocate a size of (total capaity) * (bytes needed for integer)
    If Queue's capacity is 100 and sizeof int is 8 byte then the memory of the array= 10*8= 80bytes. */

    return q;
}

// Method to see if queue is full(when size == capacity)
int isFull(struct Queue *q)
{
    return (q->size == q->capacity); // will return 1 if it's true.
}

// Method to see if queue is empty(when size == 0)
int isEmpty(struct Queue *q)
{
    return (q->size == 0);
}

// Enqueue:(changes size and rare end)
void enqueue(struct Queue *q, int item)
{
    if (isFull(q))
    {
        cout << "The Queue is full!!" << endl;
        return;
    }

    q->rare++;
    q->array[q->rare] = item; // inserting element at rare index.
    q->size++;                // increasing the size.

    cout << "The item " << item << " is successfully enqueued to queue." << endl;
}

// Dequeue:(changes size and front end)
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        cout << "The queue is empty!!" << endl;
        return;
    }

    int item = q->array[q->front];
    q->front++;

    q->size--;

    cout << "The item " << item << " is successfully dequeued" << endl;
}

// Display:
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        cout << "The queue is empty!!" << endl;
        return;
    }

    cout << "Queue elements: " << endl;
    for (int i = q->front; i <= q->rare; i++)
        cout << q->array[i] << " ";

    /*Front is always index of first element.
    Rare is always index of (size -1)*/
    cout << endl;
}

// Method to get the front of the queue:
int front(struct Queue *q)
{
    if (isEmpty(q))
        return INT_MIN;

    return q->array[q->front];
}

// Method to get the rare of the queue:
int rare(struct Queue *q)
{
    if (isEmpty(q))
        return INT_MIN;

    return q->array[q->rare];
}

int main()
{
    Queue *queue = createQueue(5); // created a queue with a capacity of 10.

    // Insertion in the queue:
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);
    display(queue);

    // Front and Rare ends of the queue:
    cout << endl;
    cout << "The front of the queue is " << front(queue) << endl;
    cout << "The rare of the queue is " << rare(queue) << endl;
    cout << endl;

    // Deletion in the queue:
    dequeue(queue);
    display(queue);

    return 0;
}