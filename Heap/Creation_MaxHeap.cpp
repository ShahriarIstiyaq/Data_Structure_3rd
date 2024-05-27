#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// Heapify Function:
void heapify(vi &a, int n, int current)
{
    /*This function takes a Node current and then comapres it with its child.
    And then makes it a max heap, where the root is greater than both its child.*/

    int maxNode = current; // This is greatest of these three nodes.
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    if (left < n && a[left] > a[maxNode])
        maxNode = left;

    if (right < n && a[right] > a[maxNode])
        maxNode = right;

    if (maxNode != current) // Base case of the recursive call.
    {
        // swaping the values.
        int temp = a[maxNode];
        a[maxNode] = a[current];
        a[current] = temp;

        heapify(a, n, maxNode);
    }
}

// Building the heap:
void buildHeap(vi &a, int n)
{
    int start = (n / 2) - 1; // staring index.
    /*All the leaf in a heap comes after the index (n/2).
     As this is 0 base index Here the starting index is (n/2)-1 */

    for (int i = start; i >= 0; i--)
        heapify(a, n, i);
}

int main()
{
    int n;
    cout << "Please enter the total number of elements in the heap: ";
    cin >> n;

    srand(time(0));
    vi a(n);

    // Inserting into the Max Heap:
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 100;
        a[i] = x;
    }
    // Displaying the array before heapifing:
    cout << "The elements of array before : \n";
    for (int i = 0; i < n; i++)
        cout << "I:" << i + 1 << " Value: " << a[i] << " " << endl;
    cout << endl;

    // Building a Max Heap:
    buildHeap(a, n);

    // Displaying the array after heapifing:
    cout << "The elements of the array in Max Heap : \n";
    for (int i = 0; i < n; i++)
        cout << "I:" << i + 1 << " Value: " << a[i] << " " << endl;
    cout << endl;

    return 0;
}
