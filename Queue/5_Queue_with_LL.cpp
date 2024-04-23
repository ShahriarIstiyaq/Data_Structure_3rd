/*----------------------Implementation of Simple Queue using Linked List----------------*/
#include <bits/stdc++.h>
using namespace std;

struct QNode
{
    int data;
    struct QNode *next;
}; // A Node of the Queue list.

struct QNode *front, *rare = NULL; // Front and rare pointer for the Queue. Here front will work as Head and rare will work as Tail of the list.
int size = 0;                      // Size of the Queue.

// A function to create an empty Queue:
struct QNode *createQueue()
{
    struct QNode *q = (struct QNode *)malloc(sizeof(struct QNode));
    return q;
}

// Enqueue:(Rare Node will change)
void enqueue(struct QNode *q, int item)
{
    // create a new Queue:
    struct QNode *Newnode = (struct QNode *)malloc(sizeof(struct QNode));
    Newnode->data = item;
    Newnode->next = NULL; // As this node will be inserted at the rare end this will be pointing to null.

    if (front == NULL && rare == NULL) // Empty queue
    {
        front = rare = Newnode; // Both front and rare moved to first node.
    }

    else
    {
        rare->next = Newnode; // First the rare node at the will point from NULL to Newnode.Then the Newnode next filed will point to NULL.
        rare = Newnode;       // Moving the rare pointer to Newnode.
    }
    size++;
    cout << "The item " << item << " is successfully Enqueued" << endl;
}

// Dequeue:(Front node will change)
void dequeue(struct QNode *q)
{
    if (front == NULL && rare == NULL) // Empty queue
    {
        cout << "The queue is empty!\n";
        return;
    }

    // store the previous node in a temp memory:
    struct QNode *temp = front;

    // Moving the front pointer to next node.
    front = front->next;

    cout << "The item " << temp->data << " is successfully dequeued" << endl;
    size--;
    free(temp); // reasing the memory of previous node.
}

void display(struct QNode *ptr)
{
    // ptr will needed to be point to the front:
    ptr = front;

    cout << "Elements of the queue:\n";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    QNode *queue = createQueue(); // created a queue with empty size.

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
            cout << "The front of the queue is " << front->data << endl;
            break;

        case 5:
            cout << endl;
            cout << "The rare of the queue is " << rare->data << endl;
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