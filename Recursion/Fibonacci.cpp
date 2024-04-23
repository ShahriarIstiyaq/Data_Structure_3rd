#include <bits/stdc++.h>
using namespace std;

void NFib(vector<int> &f, int n)
{
    if (n < 1)
    {
        cout << "Invalid input" << endl;
        return;
    }

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
}

int RFib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int fibA = RFib(n - 2);
    int fibB = RFib(n - 1);

    return fibA + fibB;
}

int main()
{
    int n;
    cout << "Please enter a number: ";
    cin >> n;

    // Recursive method:
    cout << "Fibonacci series with recursive method: \n";
    for (int i = 0; i < n; i++)
        cout << RFib(i) << " ";
    cout << endl;

    // Non-recursive method:
    vector<int> nf(n);
    NFib(nf, n);

    cout << "Fibonacci series with non-recursive method: \n";
    for (auto i : nf)
        cout << i << " ";
    cout << endl;

    return 0;
}