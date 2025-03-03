#include <iostream>
#include <iomanip>

using namespace std;

int countOnes(int number)
{
    int sumOfBinaryOnes = 0;
    while (number)
    {
        sumOfBinaryOnes += number & 1;
        number >>= 1;
    }
    return sumOfBinaryOnes;
}

int main(int argc, char const *argv[])
{
    string inputNumberInString;
    int numberOfInputs;
    cin >> numberOfInputs;

    for (int i = 0; i < numberOfInputs; i++)
    {
        cin >> inputNumberInString;
        int hexRep = std::stoi(inputNumberInString, nullptr, 16);     // process as hexa
        int decimalRep = std::stoi(inputNumberInString, nullptr, 10); // process as decimal
        cout << countOnes(decimalRep) << " " << countOnes(hexRep) << endl;
    }

    return 0;
}
