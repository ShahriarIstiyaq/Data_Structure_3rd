// Note: A factorial of 100 has 158 digits. It is not possible to store these many digits even if we use long long int.
#include <bits/stdc++.h>
using namespace std;

#define MAX 300

int mul(int num, int res[], int size)
{
    int carry = 0; // Initial carry.

    for (int i = 0; i < size; i++)
    {
        int ans = res[i] * num + carry;

        res[i] = ans % 10; // stroing last digits of product into result.

        carry = ans / 10; // putting the rest into carry.
    }

    while (carry)
    {
        res[size] = carry % 10;
        carry = carry / 10;
        size++;
    }

    return size;
}

void fact(int n)
{
    int res[MAX];
    int size = 1;
    res[0] = 1;

    for (int i = 2; i <= n; i++)
        size = mul(i, res, size);

    cout << "Factorial of 100 is: \n";
    for (int i = size - 1; i >= 0; i--)
        cout << res[i];
}

// Same as fact just used a simpler approch and vector.
void largeFactorial(int n)
{
    vector<int> res;
    res.push_back(1); // res[0]=1. minimun ans .

    for (int x = 2; x <= n; x++)
    {
        int carry = 0;

        for (int i = 0; i < res.size(); i++) // going from 0 to last index of res[] and multiplying each element with a number.
        {
            int prod = res[i] * x + carry;
            res[i] = prod % 10; // last digit of product
            carry = prod / 10;  // first digit of product is carry.
        }

        while (carry != 0)
        {
            res.push_back(carry % 10); // pusing rest of the carry in the result vector after every operations.
            carry /= 10;
        }
    }

    reverse(res.begin(), res.end());

    for (auto i : res)
        cout << i;
}


int main()
{
    fact(100);
    return 0;
}
