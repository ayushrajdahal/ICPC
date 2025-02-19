#include <iostream>

using namespace std;

int getCycleLength(int number)
{
    int cycleLength = 1;
    while (number != 1)
    {
        number = (number % 2 == 0) ? (number / 2) : (3 * number + 1);
        cycleLength += 1;
    }
    return cycleLength;
}

int main(int argc, char const *argv[])
{
    int firstNumber, secondNumber, currCycleLength, smallerNumber, biggerNumber;

    while (cin >> firstNumber >> secondNumber)
    {
        smallerNumber = min(firstNumber, secondNumber);
        biggerNumber = max(firstNumber, secondNumber);

        int maxCycleLength = 0;

        for (int i = smallerNumber; i <= biggerNumber; i++)
        {
            currCycleLength = getCycleLength(i);
            if (currCycleLength > maxCycleLength)
            {
                maxCycleLength = currCycleLength;
            }
        }

        cout << firstNumber << " " << secondNumber << " " << maxCycleLength << endl;
    }

    return 0;
}
