#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long n, sumOfN, currentNum;

    cin >> n;
    sumOfN = 0;

    for (long long i = 1; i < n; i++)
    {
        cin >> currentNum;
        sumOfN += currentNum;
    }

    cout << n * (n + 1) / 2 - sumOfN << endl;
    return 0;
}
