/*----------------------Implementation of Priority Queue using Linked List----------------*/
#include <bits/stdc++.h>
using namespace std;

struct QNode
{
    int data;
    int priority;
    struct QNode *next;
}; // A Node of the Queue list.

int size = 0;     // Size of the Queue.
int capacity = 0; // Maximum capacity of the Queue.

// A function to create an empty Queue:
struct QNode *createQueue(int cap)
{
    capacity = cap;
    return nullptr; // Return nullptr indicating an empty queue
}

bool isEmpty()
{
    return (size == 0);
}

bool isFull()
{
    return (size == capacity);
}

int peek(QNode *head)
{
    return head->data;
}

void dequeue(QNode **head)
{
    if (isEmpty()) // Empty queue
    {
        cout << "The queue is empty!\n";
        return;
    }

    QNode *temp = *head; // storing current head node to a temporary memory .
    cout << "The item " << temp->data << " is successfully dequeued" << endl;

    (*head) = (*head)->next; // Moving the head pointer to the next node.

    size--;
    free(temp);
}

void enqueue(QNode **head, int item, int p)
{
    if (isFull())
    {
        cout << "Queue is full!!" << endl;
        return;
    }

    // Creating new node:
    QNode *Newnode = new QNode; // Allocate memory for the new node
    Newnode->data = item;
    Newnode->priority = p;
    Newnode->next = NULL;

    if (*head == nullptr || (*head)->priority < p) // The head node priority is less than new node.
    {
        // Placed the Newnode before head and move the head to newnode.
        Newnode->next = (*head);
        (*head) = Newnode;
    }

    else
    {
        QNode *ptr = (*head);
        // Travseing the list to find a position to insert with right priority.
        while (ptr->next != NULL && ptr->next->priority > p)
            ptr = ptr->next;

        Newnode->next = ptr->next;
        ptr->next = Newnode;
    }

    size++;
    cout << "The item " << item << " is successfully Enqueued" << endl;
}

void display(QNode *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

int main()
{
    int cap;
    cout << "Please enter the size of the queue: ";
    cin >> cap;
    QNode *queue = createQueue(cap);
    QNode *head = queue;

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
            enqueue(&head, item, priority);
            break;

        case 2:
            dequeue(&head);
            break;

        case 3:
            display(head);
            break;

        case 4:
            cout << endl;
            cout << "The peek of the queue is " << peek(head) << endl;
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
