#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void twoSets(ll n)
{
    ll sumOfAll = n * (n + 1) / 2;

    if (sumOfAll % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<ll> setOne;
    vector<ll> setTwo;

    ll sumOne = 0;
    ll sumTwo = 0;

    for (ll i = n; i > 0; i--)
    {
        if (sumOne < sumTwo)
        {
            setOne.push_back(i);
            sumOne += i;
        }
        else
        {
            setTwo.push_back(i);
            sumTwo += i;
        }
    }

    cout << setOne.size() << endl;

    for (ll oneNum : setOne)
    {
        cout << oneNum << " ";
    }
    cout << endl;

    cout << setTwo.size() << endl;

    for (ll twoNum : setTwo)
    {
        cout << twoNum << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    twoSets(n);
    return 0;
}
