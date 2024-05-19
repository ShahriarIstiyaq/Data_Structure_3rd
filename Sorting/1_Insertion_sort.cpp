#include <bits/stdc++.h>
using namespace std;

void insertioSort(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int ptr = i - 1;

        while (temp < a[ptr] && ptr >= 0)
        {
            a[ptr + 1] = a[ptr];
            ptr = ptr - 1;
        }
        a[ptr + 1] = temp;
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
    insertioSort(a, n);

    // Console output:
    cout << "\nData after sorting-> \n";
    cout << "The array:" << endl;
    for (auto i : a)
        cout << i << " ";

    // Implemention insertion sort with insertion:
    int x;
    cout << "\nPlease enter an element: ";
    cin >> x;
    a.push_back(x);

    insertioSort(a, n + 1);

    // Console output:
    cout << "\nData after taking a new element as input -> \n";
    cout << "The array:" << endl;
    for (auto i : a)
        cout << i << " ";

    return 0;
}