#include <bits/stdc++.h>
using namespace std;
#define size 50

int Queue[size + 1];       // Queue.
int adj[size][size] = {0}; // Adjacency Matrix.
int n;

int front = 0, rear = 0;

// Queue operation:
void enqueue(int item)
{

    if ((front == 1 && rear == size) || front == rear + 1)
    {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == 0)
    {
        front = 1;
        rear = 1;
    }
    else
        rear++;

    Queue[rear] = item;
}

int dequeue()
{
    int item;
    if (front == 0)
    {
        cout << "underflow" << endl;
        return -1;
    }

    item = Queue[front];

    if (front == rear)
    {
        front = 0;
        rear = 0;
    }

    else
        front = front + 1;

    return item;
}

// Creating an adjacent matrix of an undirected graph:
void createAjdMat()
{
    int max_edges, i, j, origin, destin;

    cout << "enter number of vertices: ";
    cin >> n;

    max_edges = n * (n - 1) / 2;

    for (i = 0; i < max_edges; i++)
    {
        cout << "Enter origin and destination (0 0 to quit):";
        cin >> origin >> destin;

        if (origin == 0 && destin == 0)
        {
            break;
        }

        adj[origin][destin] = 1;
        adj[destin][origin] = 1;
    }

    cout << "The adjacency matrix is:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// Function for BFS:
void bfs()
{
    int i;
    int exploring;
    int visited[n] = {0}; // Initialize visited as 0 since no node is yet visited

    cout << "Choose node to begin BFS traversal: ";
    cin >> i;

    cout << "Breadth First Traversal starting from node " << i << ": ";

    visited[i] = 1; // The first node is always considered as visited.

    cout << i << " ";

    enqueue(i); // Inserting first node in queue

    while (front != 0 && rear != 0) // Will explore till queue is empty
    {
        exploring = dequeue();
        for (int j = 0; j < n; j++)
        {

            if (adj[exploring][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

int main()
{
    createAjdMat();
    bfs();

    return 0;
}