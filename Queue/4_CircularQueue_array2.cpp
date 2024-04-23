/*----------------------Implementation of Cicular Queue using array by dynamic memory allocation----------------*/

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

    q->capacity = cap;       // total capacity of queue.
    q->front = q->rare = -1; // both of front and back are at -1 th index.
    q->size = 0;

    q->array = (int *)malloc(q->capacity * sizeof(int));
    /*This will allocate a size of (total capaity) * (bytes needed for integer)
    If Queue's capacity is 100 and sizeof int is 8 byte then the memory of the array= 10*8= 80bytes. */

    return q;
}

// Method to see if queue is full(when size == capacity)
int isFull(struct Queue *q)
{
    return ((q->front == 0 && q->rare == (q->capacity - 1)) || (q->rare + 1) % q->capacity == q->front); // will return 1 if it's true.
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
        cout << "Queue is full!!" << endl;
        return;
    }

    else if (q->front == -1) // For the first element.
    {
        q->front = q->rare = 0;
        q->array[q->rare] = item;
    }

    else if (q->rare == (q->capacity - 1) && q->front != 0) // There are some empty spaces infront of front end.
    {
        q->rare = 0; // reseting the rare.
        q->array[q->rare] = item;
    }

    else // Normal situation
    {
        q->rare++;
        q->array[q->rare] = item;
    }

    q->size++; // Increment the size of the queue.
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

    if (q->front == q->rare) // The queue has emptied out.
    {
        q->front = q->rare = -1;
    }

    else if (q->front == q->capacity - 1)
        q->front = 0;

    else
        q->front++;

    q->size--; // Decresing the size.
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

    if (q->rare >= q->front) // Normal situation.
    {
        for (int i = q->front; i <= q->rare; i++)
            cout << q->array[i] << " ";
        cout << endl;
    }

    else // When rare < front
    {
        for (int i = q->front; i < q->size; i++)
            cout << q->array[i] << " ";

        for (int i = 0; i <= q->rare; i++)
            cout << q->array[i] << " ";

        cout << endl;
    }
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
    Queue *queue = NULL; // created a queue with empty size.
    cout << "Please enter the max size of the queue: ";
    int cap;
    cin >> cap;
    queue = createQueue(cap); // Initializing the max size of the queue.

    int choice, item;
    do
    {
        printf("\n-----------Main Menu-------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. GetFront\n");
        printf("5. GetRare\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:
            cout << "Enter value to enqueue: ";
            cin >> item;
            enqueue(queue, item);
            break;

        case 2:
            dequeue(queue);
            break;

        case 3:
            display(queue);
            break;

        case 4:
            cout << endl;
            cout << "The front of the queue is " << front(queue) << endl;
            break;

        case 5:
            cout << endl;
            cout << "The rare of the queue is " << rare(queue) << endl;
            break;

        case 6:
            printf("<-End operation->\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}