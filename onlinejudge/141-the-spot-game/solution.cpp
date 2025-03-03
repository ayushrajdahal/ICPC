#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

set<pair<ll, ll>> currentBoardState;
set<set<pair<ll, ll>>> previousBoardStates;
ll N; // NOTE: board size is N x N

set<pair<ll, ll>> rotateBy90(set<pair<ll, ll>> boardState)
{
    set<pair<ll, ll>> newBoardState;

    for (const auto &p : boardState) // MODIFIED from for (pair<ll, ll> p : boardState)
    {
        newBoardState.insert(make_pair(p.second, N - 1 - p.first));
    }
    return newBoardState;
}

bool processBoard(ll x, ll y, string moveType, ll currentRound)
{
    bool isFirstPlayer = currentRound & 1;

    // check if it is an insert move or an erase move
    if (moveType == "+")
    {
        currentBoardState.insert(make_pair(x, y));
    }
    else if (moveType == "-")
    {
        currentBoardState.erase(make_pair(x, y));
    }

    // see if this board state was already achieved
    if (previousBoardStates.find(currentBoardState) != previousBoardStates.end())
    {
        if (isFirstPlayer)
        {
            cout << "Player 1 wins in round " << currentRound << endl;
        }
        else
        {
            cout << "Player 2 wins in round " << currentRound << endl;
        }
        return true;
    }

    previousBoardStates.insert(currentBoardState); // insert first state w/o rotation
    // iteratively rotate by 90, get the 3 other states, apppend into previous states.
    for (int i = 0; i < 3; i++)
    {
        currentBoardState = rotateBy90(currentBoardState);
        previousBoardStates.insert(currentBoardState);
    }
}

int main(int argc, char const *argv[])
{
    ll player1Move, player2Move, x, y;
    string moveType;

    while (cin >> N)
    {
        if (N == 0)
        {
            break;
        }

        for (ll round = 1; round <= 2 * N; round++)
        {
            cin >> x >> y >> moveType;
            if (processBoard(x, y, moveType, round))
            {
                // NOTE: need to read the remaining board moves, but IGNORE them.
                for (ll i = round + 1; i <= 2 * N; i++)
                {
                    cin >> x >> y >> moveType;
                }
                break;
            };
        }

        previousBoardStates.clear();
        currentBoardState.clear();
    }
    return 0;
}
