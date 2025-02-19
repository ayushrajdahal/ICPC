#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long numberOfInputs, previousInput, currentInput, numOperations;

    cin >> numberOfInputs >> previousInput;

    numOperations = 0;

    for (long long i = 1; i < numberOfInputs; i++)
    {
        cin >> currentInput;

        while (currentInput < previousInput)
        {
            currentInput++;
            numOperations++;
        }

        previousInput = currentInput;
    }
    cout << numOperations << endl;
    return 0;
}
