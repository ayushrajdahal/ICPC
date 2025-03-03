#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cycleLengths;

int getCycleLength(int number)
{
    int cycleLength = 0;

    if (cycleLengths.find(number) != cycleLengths.end())
    {
        return cycleLengths[number];
    }

    if (number == 1)
    {
        cycleLength = 1;
    }
    else if (number % 2 == 0)
    {
        cycleLength = 1 + getCycleLength(number / 2);
    }
    else
    {
        cycleLength = 1 + getCycleLength(3 * number + 1);
    }
    cycleLengths[number] = cycleLength;
    return cycleLength;
}

int main(int argc, char const *argv[])
{
    int firstNumber, secondNumber, smallerNumber, biggerNumber, currCycleLength, maxCycleLength;

    while (cin >> firstNumber >> secondNumber)
    {
        smallerNumber = min(firstNumber, secondNumber);
        biggerNumber = max(firstNumber, secondNumber);

        maxCycleLength = 0;

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
