#include <bits/stdc++.h>
using namespace std;
#define size 50

int adjm[size][size] = {0};
int n;

// Creating an adjacent matrix of an undirected graph:
void createAjdMat()
{
    int max_edges, i, j, origin, destin;

    cout << "enter number of vertices: ";
    cin >> n;

    max_edges = n * (n - 1) / 2;

    for (i = 0; i < max_edges; i++)
    {
        cout << "Enter origin and destination (0 0 to quit): ";
        cin >> origin >> destin;

        if (origin == 0 && destin == 0)
        {
            break;
        }

        adjm[origin][destin] = 1;
        adjm[destin][origin] = 1;
    }

    cout << "The adjacency matrix is:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
}
// Function for DFS:
void dfs(int i, int visited[])
{
    if (visited[i] == 1) // Base case.
        return;

    cout << i << " ";

    visited[i] = 1;

    for (int j = 0; j < n; j++)
        if (adjm[i][j] == 1 && visited[j] == 0)
            dfs(j, visited);
}
int main()
{
    createAjdMat();

    int visited[n] = {0};

    int firstNode;
    cout << "Choose first node to begin traversal: ";
    cin >> firstNode;
    dfs(firstNode, visited);

    return 0;
}