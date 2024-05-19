#include <bits/stdc++.h>
using namespace std;

// Finding the minimum element:
int MIN(vector<int> &a, int n, int loc)
{
    int min = a[loc];
    // int min_index;
    for (int i = loc + 1; i < n; i++)
        if (a[i] < min)
        {
            min = a[i];
            loc = i;
        }

    return loc;
}

// Selection sort:
void selectionSort(vector<int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = MIN(a, n, i);

        // swapping current element with minimum.
        if (min_index != i)
        {
            int temp = a[min_index];
            a[min_index] = a[i];
            a[i] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Please enter total number of elements: ";
    cin >> n;

    vector<int> a(n);

    // Genetating N elements in the array:
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        int x = rand();
        a[i] = x;
    }

    // Console output:
    cout << "\nData before sorting-> \n";
    cout << "The array:" << endl;
    for (auto i : a)
        cout << i << " ";

    // Sorting:
    selectionSort(a, n);

    // Console output:
    cout << "\nData after sorting-> \n";
    cout << "The array:" << endl;
    for (auto i : a)
        cout << i << " ";
        
    return 0;
}
