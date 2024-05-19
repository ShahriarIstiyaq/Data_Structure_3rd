#include <bits/stdc++.h>
using namespace std;

// Marge fuction for maging two sorted arrays:
void marge(vector<int> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays:
    vector<int> l1(n1), l2(n2);

    // copying data:
    for (int i = 0; i < n1; i++)
        l1[i] = a[left + i];

    for (int i = 0; i < n2; i++)
        l2[i] = a[mid + 1 + i];

    // Marging the sorted lists:
    int s1 = 0, s2 = 0; // counter to track the elements of the list 1 and 2.
    int k = left;       // counter of main list.
    while (s1 < n1 && s2 < n2)
    {
        if (l1[s1] <= l2[s2]) // when the elments of the list 1 is less than the elments of the list 2.
        {
            a[k] = l1[s1];
            s1++;
        }

        else
        {
            a[k] = l2[s2];
            s2++;
        }
        k++;
    }

    // Adding the reaming elments of the list1:
    while (s1 < n1)
    {
        a[k] = l1[s1];
        s1++;
        k++;
    }

    // Adding the reaming elments of the list2:
    while (s2 < n2)
    {
        a[k] = l2[s2];
        s2++;
        k++;
    }
}

// Marge sort function:
void margesort(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // sort first and second halves:
        margesort(a, left, mid);
        margesort(a, mid + 1, right);

        // Marging the sorted halves:
        marge(a, left, mid, right);
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
        int x = rand() % 100;
        a[i] = x;
    }

    // Console output:
    cout << "\nData before sorting-> \n";
    cout << "The array:" << endl;
    for (auto i : a)
        cout << i << " ";

    // Sorting:
    margesort(a, 0, n - 1);

    // Console output:
    cout << "\nData after sorting-> \n";
    cout << "The array:" << endl;
    for (auto i : a)
        cout << i << " ";

    return 0;
}
