#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int maxLength = 0;
    int currLength = 0;
    string sequence;

    cin >> sequence;
    char prevChar = sequence.at(0);

    for (int i = 0; i < sequence.size(); i++)
    {
        char c = sequence[i];

        if (c == prevChar)
        {
            currLength++;
        }
        else
        {
            currLength = 1;
        }
        maxLength = max(currLength, maxLength);
        prevChar = c;
    }
    cout << maxLength << endl;
    return 0;
}
