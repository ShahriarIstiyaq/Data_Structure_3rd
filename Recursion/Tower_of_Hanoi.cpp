#include <bits/stdc++.h>
using namespace std;

void tower(int n, char beg, char aux, char end)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from rod " << beg << " to rod " << end << endl;
        return;
    }

    tower(n - 1, beg, end, aux);
    cout << "Move disk " << n << " from rod " << beg << " to rod " << end << endl;

    tower(n - 1, aux, beg, end);
}

int main()
{
    int n;
    cout << "Please enter the number of disks: ";
    cin >> n;

    tower(n, 'A', 'B', 'C');
    return 0;
}