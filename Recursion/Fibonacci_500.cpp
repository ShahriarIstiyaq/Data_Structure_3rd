#include <bits/stdc++.h>
using namespace std;

long long int NFib(int n)
{

    if (n < 1)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<long long int> f(n + 1);

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    return f[n]; // Nth element of the sequence.
}

int main()
{
    cout << "The n th Fibonacci number is: " << NFib(500) << endl;
    return 0;
}
