#include <iostream>

using namespace std;

void printPermutations(long n)
{
    // even first because of the special case when n = 4, soln = [2 4 1 3] and not [1 3 2 4]
    for (long i = 2; i <= n; i += 2)
    {
        cout << i << " ";
    }

    for (long i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    long n;
    cin >> n;

    if (n < 4 && n != 1) // when n=1, we just print itself.
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        printPermutations(n);
    }

    return 0;
}
