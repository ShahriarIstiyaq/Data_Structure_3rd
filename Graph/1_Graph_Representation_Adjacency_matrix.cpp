#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>

vvi creatAdjMatrix(int n)
{
    int maxEdges, origin, destin;
    char graphType;

    // Initializing the adjacency matrix with zeros
    vvi adjm(n + 1, vi(n + 1, 0));

    cout << "Enter type of graph, directed or undirected (d/u) : ";
    cin >> graphType;

    if (graphType == 'u') // if the graph is undirected , maximum edges possible is = n*(n-1)/2
        maxEdges = ((n * (n - 1)) / 2);

    else // if the graph is directed , maximum edges possible is = n*(n-1)
        maxEdges = n * (n - 1);

    // Taking input:
    for (int i = 1; i <= maxEdges; i++)
    {
        cout << "Enter origin and destination (0 0 to quit):"; // The nodes between which there will be an edge.
        cin >> origin >> destin;

        if (origin == 0 && destin == 0) // Exit.
            break;

        if (origin > n || destin > n || origin <= 0 || destin <= 0) // When the input is out of bound.
        {
            cout << "Invalid Input" << endl;
            i--;
        }

        else
        {
            adjm[origin][destin] = 1; // For only one direction

            if (graphType == 'u')
                adjm[destin][origin] = 1; // For other direction in undirected graphs. Becouse in undirected graph one can go both ways.
        }
    }

    return adjm;
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    vvi adj = creatAdjMatrix(n); // The adjacency matrix.

    // Console output:
    cout << "\nThe Adjacency matrix is: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }

    return 0;
}
