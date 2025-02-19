#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int buffer;
int anotherBuffer;

int numPlayers;
bool playNextGame;
int board[100] = {0};
vector<int> diceRolls;
unordered_set<int> loseTurnSquares;
unordered_set<int> extraTurnSquares;

int playGame(int numPlayers)
{
    // chutes and ladders: set target square as the value of current square array.
    cout << "Give all the snakes and latter combinations:" << endl;
    cin >> buffer;
    cin >> anotherBuffer;
    while (!(buffer == 0 && anotherBuffer == 0))
    {
        board[buffer] = anotherBuffer;
        cin >> buffer;
        cin >> anotherBuffer;
    };

    // get lose-a-turn and extra-turn squares
    cout << "Give all the lose-a-turn and extra-turn squares:" << endl;
    cin >> buffer;
    while (buffer != 0)
    {
        if (buffer < 0)
        {
            loseTurnSquares.insert(abs(buffer));
        }
        else
        {
            extraTurnSquares.insert(buffer);
        }
        cin >> buffer;
    }

    // play game
    int currentPlayer = 0;
    vector<int> playerPositions(numPlayers, 0);
    vector<int> playerStates(numPlayers, 0);

    for (int diceRoll : diceRolls)
    {
        // skip the player with lose-a-turn value
        if (playerStates[currentPlayer] == -1)
        {
            playerStates[currentPlayer++] = 0;
            currentPlayer %= numPlayers;
        }

        int currentPosition = playerPositions[currentPlayer] + diceRoll;
        if (board[currentPosition] != 0)
        {
            currentPosition = board[currentPosition];
        }
        playerPositions[currentPlayer] = currentPosition;

        if (currentPosition == 100)
        {
            cout << "Winner: " << currentPlayer;
        }

        if (loseTurnSquares.find(currentPosition) != loseTurnSquares.end())
        {
            playerStates[currentPlayer] = -1;
        }
        else if (extraTurnSquares.find(currentPosition) != extraTurnSquares.end())
        {
            continue;
        }
        else
        {
            playerStates[currentPlayer] = 0;
            currentPlayer++;
        };

        if (currentPlayer >= numPlayers)
        {
            currentPlayer = 0;
        }
    }

    // get number of players for the next game.
    cin >> numPlayers;

    // if 0 is passed, no new game.
    if (numPlayers != 0)
        return true;

    return false;
}

int main(int argc, char const *argv[])
{
    // get all the dice rolls
    cout << "Give all the dice rolls:" << endl;
    cin >> buffer;
    while (buffer != 0)
    {
        diceRolls.push_back(buffer);
        cin >> buffer;
    }

    cout << "give number of players:" << endl;
    // get number of players
    cin >> numPlayers;

    do
    {
        playNextGame = playGame(numPlayers);
    } while (playNextGame);

    return 0;
}
