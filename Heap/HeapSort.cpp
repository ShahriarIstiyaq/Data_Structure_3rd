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

// Heap sort function:
void heapSort(vi &a, int n)
{
    buildHeap(a, n);                // Builds a Max heap from the array.
    for (int i = n - 1; i > 0; i--) // start from i'th element  === [40 30 15 10 20]
    {                               //                                           i
                                    // swap i'th element with root. as root is max . now i'th element is sorted ==== [20 30 15 10   | 40]
        int temp = a[i];            // now i=i-1 which means last element is excluded . heapify the remaining elements so that max is at root === [20 30 15 10   | 40]
        a[i] = a[0];                //                                                                                                                       i
        a[0] = temp;                // after heapification [30 20 15 10   | 40]
                                    //                               i
        heapify(a, i, 0);
    }
}
int main()
{
    int n;
    cout << "Please enter total number of elements in the heap: ";
    cin >> n;

    srand(time(0));
    vi a(n);

    for (int i = 0; i < n; i++)
    {
        int x = rand() % 100;
        a[i] = x;
    }

    // Dispalying the array before sort:
    cout << "The array before sort: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // Heapsort:
    heapSort(a, n);

    // Displaying the array after sort:
    cout << "The array after sort: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}