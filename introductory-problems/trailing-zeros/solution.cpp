#include <iostream>

using namespace std;
typedef long long ll;

ll trailing_zeros(ll n)
{
    ll numberOfFives = 0;

    // LOGIC:
    // we're counting no. of zeros, i.e. no. of times we have to do 10x.
    // we know 10 can be factored into prime factors 2 and 5. we know that 2 is abundant since every even number is a multiple of 2.
    // so, we count no. of fives in n!, which is the same as going through all numbers from 0 to n sequentially, seeing which ones are divisible by 5
    // 25,125,5,25,125, etc. are counted as many times as the no. of fives in the factor. eg: 50 is counted two times since it's divisble by both 5 and 25

    for (ll divisor = 5; divisor <= n; divisor *= 5)
    {
        numberOfFives += n / divisor;
    }
    return numberOfFives;
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    cout << trailing_zeros(n) << endl;
    return 0;
}
