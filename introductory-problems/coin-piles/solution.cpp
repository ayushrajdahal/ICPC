#include <iostream>

using namespace std;
typedef long long ll;

string coinPiles(ll a, ll b)
{
    if (((a + b) % 3 != 0) || (a > 2 * b) || (b > 2 * a))
    {
        return "NO";
    }

    return "YES";
}

int main(int argc, char const *argv[])
{
    ll numberOfInputs, a, b;

    cin >> numberOfInputs;

    while (numberOfInputs--)
    {
        cin >> a >> b;
        cout << coinPiles(a, b) << endl;
    }

    return 0;
}