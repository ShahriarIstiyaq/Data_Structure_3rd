#include <bits/stdc++.h>
using namespace std;

// A node whose adjacency list will be added to it.
struct adjNode
{
    int node; // Vertice.
    adjNode *next;
};

void CreateGraph(adjNode *adjlist[], int numVertices)
{
    for (int i = 0; i < numVertices; i++)
        adjlist[i] = NULL;
}

void addEdge(adjNode *adjList[], int n, int v)
{
    adjNode *newNode = (adjNode *)malloc(sizeof(adjNode));
    newNode->node = v;
    newNode->next = adjList[n];
    adjList[n] = newNode;
}

void Display(adjNode *adjList[], int numVertices)
{
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Node " << i;
        adjNode *temp = adjList[i];
        while (temp)
        {
            cout << " -> " << temp->node;
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    int n = 4; // number of vertices.
    adjNode *adjList[n];

    CreateGraph(adjList, n);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 1);

    Display(adjList, n);

    return 0;
}
