#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll fast_exponentiation(ll number, ll exponent) {
    ll result = 1;
    while (exponent)
    {
        if (exponent & 1LL) {
            result = (result * number) % MOD; // !!!
        }
        number = (number * number) % MOD; // !!!
        exponent >>= 1LL;
    }
    
    return result;
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    cout << fast_exponentiation(2LL, n) << endl;
    return 0;
}