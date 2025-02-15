#include <iostream>
#include <cmath>

using namespace std;

const long double ROOT_THREE_BY_TWO = sqrt(3.0) / 2.0; // 64-bit data type for more accurate calculations
int numberOfRows, rectangleWidthRoundedDown, numberOfPipes;

int grid(const double rectangleHeight, const double rectangleWidth)
{
    return static_cast<int>(rectangleHeight) * static_cast<int>(rectangleWidth);
}

int skewA(const double rectangleHeight, const double rectangleWidth)
{
    rectangleWidthRoundedDown = static_cast<int>(rectangleWidth);

    int numberOfRows = static_cast<int>(((rectangleHeight - 1.0) / ROOT_THREE_BY_TWO) + 1); // int type rounds down the result

    int numberOfEvenRows = numberOfRows / 2; // rounding down again
    int numberOfOddRows = numberOfRows - numberOfEvenRows;

    numberOfPipes = numberOfEvenRows * (rectangleWidthRoundedDown - 1) + numberOfOddRows * rectangleWidthRoundedDown; // there are n-1 elements in even rows, n elements in odd rows

    return numberOfPipes;
}

int skewB(const double rectangleHeight, const double rectangleWidth)
{
    rectangleWidthRoundedDown = static_cast<int>(rectangleWidth);

    numberOfRows = static_cast<int>(((rectangleHeight - 1.0) / ROOT_THREE_BY_TWO) + 1); // int type rounds down

    int numPipesInARow = (rectangleWidth - rectangleWidthRoundedDown) < 0.5 ? rectangleWidthRoundedDown - 1 : rectangleWidthRoundedDown;

    numberOfPipes = numPipesInARow * numberOfRows; // no. of pipes is the same throughout all rows here, unlike skewA.

    return numberOfPipes;
};

int main()
{
    double a, b;

    while (cin >> a >> b)
    {
        if (a < 1 || b < 1)
        {
            cout << 0 << endl;
            continue;
        }

        int gridOutput = grid(a, b); // this would equal grid(b,a) since we're doing the same operations to rows & cols. no comparison necessary

        int maxSkewOutput = max(max(max(skewA(a, b), skewA(b, a)), skewB(a, b)), skewB(b, a)); // run all the combinations through all skew functions, get the max.

        if (gridOutput >= maxSkewOutput) // we prefer grids to skews when the outputs are equal.
        {
            cout << gridOutput << " " << "grid" << endl;
        }
        else
        {
            cout << maxSkewOutput << " " << "skew" << endl;
        }
    }
    return 0;
}
