#include <bits/stdc++.h>
using namespace std;

// Comparator for  Quick sort:
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
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
    // qsort() is designed to work with the array. It will show error with the vector.[-> qsort(a, n, sizeof(int), compare); <-]

    qsort(a.data(), n, sizeof(int), compare); // Here a.data() returns the first elements of the vector.

    // Console output:
    cout << "\nData after sorting-> \n";
    cout << "The array:" << endl;
    for (auto i : a)
        cout << i << " ";

    return 0;
}
