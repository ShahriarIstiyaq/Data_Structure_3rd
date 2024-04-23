#include <iostream>
using namespace std;

int RFact(int n) // Factorial of a with recursive method
{
    return (n == 0 || n == 1) ? 1 : n * RFact(n - 1);
}

int NFact(int n) // Factorial of a with non-recursive method
{
    if (n == 0 || n == 1)
        return 1;

    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;

    return fact;
}

int main()
{
    int x;
    cout << "Please enter a number to its factorial:  ";
    cin >> x;

    cout << "Factorial of " << x << " using recursive method is " << RFact(x) << endl;
    cout << "Factorial of " << x << " using non-recursive method is " << NFact(x) << endl;

    return 0;
}
