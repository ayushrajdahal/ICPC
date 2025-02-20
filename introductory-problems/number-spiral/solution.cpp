#include <iostream>

using namespace std;

long getNthDiagonal(long n)
{
    n = n - 1;
    return 1 + n * (n + 1);
}

long bottomHalf(long y, long x)
{
    if (y % 2 == 0)
    {
        return getNthDiagonal(y) + (y - x);
    }
    else
    {
        return getNthDiagonal(y) - (y - x);
    }
}

long topHalf(long y, long x)
{
    if (x % 2 == 0)
    {
        return getNthDiagonal(x) - (x - y);
    }
    else
    {
        return getNthDiagonal(x) + (x - y);
    }
}

int main(int argc, char const *argv[])
{
    long numberOfInputs, y, x;
    cin >> numberOfInputs;

    for (long i = 0; i < numberOfInputs; i++)
    {
        cin >> y >> x;
        if (y == x)
        {
            cout << getNthDiagonal(x);
        }
        else if (y > x)
        {
            cout << bottomHalf(y, x);
        }
        else
        {
            cout << topHalf(y, x);
        }
        cout << endl;
    }
    return 0;
}
