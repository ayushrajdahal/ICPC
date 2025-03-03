#include <iostream>
#include <bitset>

using namespace std;
typedef long long ll;

ll fast_exp(ll base, ll exponent)
{
    ll out_val = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            out_val *= base;
        }
        base *= base;
        exponent >>= 1; // MISTAKE: forgot to shift
    }
    return out_val;
}

void gray_code(ll n)
{
    ll max_val = fast_exp(2, n) - 1;
    for (ll i = 0; i <= max_val; i++)
    {
        ll out_val = i ^ (i >> 1);
        cout << bitset<64>(out_val).to_string().substr(64 - n) << endl;
    }
    return;
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    gray_code(n);
    return 0;
}
