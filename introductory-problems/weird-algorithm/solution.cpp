#include <iostream>

using namespace std;

long long nextValue(long long currentValue)
{
    return currentValue % 2 == 0 ? currentValue / 2 : currentValue * 3 + 1;
}

int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        n = nextValue(n);
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
