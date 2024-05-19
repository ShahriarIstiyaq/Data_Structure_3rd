#include <bits/stdc++.h>
using namespace std;

// Marge Sort for 2 sorted list.
vector<int> margeSort(vector<int> &l1, vector<int> &l2)
{
    vector<int> newList;
    int s1 = 0, s2 = 0; // counter to track the elements of the list 1 and 2.
    while (s1 < l1.size() && s2 < l2.size())
    {
        if (l1[s1] < l2[s2]) // when the elments of the list 1 is less than the elments of the list 2.
        {
            newList.push_back(l1[s1]);
            s1++;
        }

        else
        {
            newList.push_back(l2[s2]);
            s2++;
        }
    }

    // Adding the reaming elments of the list1:
    while (s1 < l1.size())
    {
        newList.push_back(l1[s1]);
        s1++;
    }

    // Adding the reaming elments of the list2:
    while (s2 < l2.size())
    {
        newList.push_back(l2[s2]);
        s2++;
    }

    return newList;
}

int main()
{
    /// Initializing list1:
    int n1;
    cout << "Please enter total number of elements in list1: ";
    cin >> n1;
    vector<int> l1(n1);

    // Genetating n1 elements in the lis1:
    srand(time(0));

    for (int i = 0; i < n1; i++)
    {
        int x = rand() % 100;
        l1[i] = x;
    }

    // sorting list1 & displaying:
    sort(l1.begin(), l1.end());
    cout << "Elements in list1 are: \n";
    for (int i = 0; i < n1; i++)
        cout << l1[i] << " ";

    cout << endl;

    /// Initializing list2:
    int n2;
    cout << "\nPlease enter total number of elements in list2: ";
    cin >> n2;
    vector<int> l2(n2);

    // Genetating n2 elements in the lis2:

    for (int i = 0; i < n2; i++)
    {
        int x = rand() % 100;
        l2[i] = x;
    }

    // sorting list1 & displaying:
    sort(l2.begin(), l2.end());
    cout << "\nElements in list2 are: \n";
    for (auto i : l2)
        cout << i << " ";

    cout << endl;

    // Sorting:
    vector<int> sortedList = margeSort(l1, l2);
    // Console output:
    cout << "\nData after marge sorting-> \n";
    cout << "The Marge List:" << endl;
    for (auto i : sortedList)
        cout << i << " ";

    return 0;
}
