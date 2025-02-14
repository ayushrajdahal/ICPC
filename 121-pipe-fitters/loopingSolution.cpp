#include <iostream>
#include <cmath>

using namespace std;

const double ROOT_THREE_BY_TWO = sqrt(3.0) / 2.0;

int grid(float rectangleHeight, float rectangleWidth)
{
    return (int)rectangleHeight * (int)rectangleWidth;
}

int skewA(float rectangleHeight, float rectangleWidth)
{
    int maxIntWidth = (int)rectangleWidth;
    double currHeight = 1.0;
    int numberOfPipes = 0;
    for (int i = 0; (currHeight + ROOT_THREE_BY_TWO) <= rectangleHeight; i++)
    {
        // alternating number of pipes in every layer, varying betn n and n-1.
        if (i % 2 == 0)
        {
            numberOfPipes += maxIntWidth;
        }
        else
        {
            numberOfPipes += maxIntWidth - 1;
        }

        // starting second layer, height increases by sqrt(3)/2 in every step.
        if (i > 0)
            currHeight += ROOT_THREE_BY_TWO;
    }
    return numberOfPipes;
}

int skewB(float rectangleHeight, float rectangleWidth)
{
    float rectangleWidthRoundedDown = (int)rectangleWidth;
    int numPipesInARow;

    numPipesInARow = (rectangleWidth - rectangleWidthRoundedDown) < 0.5 ? (int)(rectangleWidthRoundedDown - 1) : (int)rectangleWidthRoundedDown;

    double currHeight = 1.0;
    int numberOfPipes = 0;
    for (int i = 0; (currHeight + ROOT_THREE_BY_TWO) <= rectangleHeight; i++)
    {
        numberOfPipes += numPipesInARow;
        if (i > 0)
            currHeight += ROOT_THREE_BY_TWO;
    }
    return numberOfPipes;
};

int main(int argc, char const *argv[])
{
    float a, b;
    int gridOutput, maxSkew;

    while (cin >> a >> b)
    {
        if (a < 1 || b < 1)
        {
            cout << 0 << endl;
            continue;
        }

        gridOutput = grid(a, b);
        maxSkew = max(max(max(skewA(a, b), skewA(b, a)), skewB(a, b)), skewB(b, a));

        if (gridOutput >= maxSkew)
        {
            cout << gridOutput << " " << "grid" << endl;
        }
        else
        {
            cout << maxSkew << " " << "skew" << endl;
        }
    }
    return 0;
}
