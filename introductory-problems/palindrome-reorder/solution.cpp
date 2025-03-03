#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

void palindrome_reorder(string s)
{
    unordered_map<char, ll> charCount;
    string odd_char = "";
    string out_str = "";

    for (char c : s)
    {
        charCount[c]++;
    }

    for (auto &[character, count] : charCount)
    {
        // if there is an odd count for a char, keep ONE of those chars in the middle for symmetry. the rest, put wherever.
        if (count & 1)
        {
            if (odd_char != "") // already seen an odd char
            {
                cout << "NO SOLUTION" << endl;
                return;
            }
            odd_char = character;
        }

        string half_string((int)(count / 2), character); // joins ⌊count/2⌋ no. of characters into a str

        out_str += half_string; // building up to the first half
    }

    out_str = out_str + odd_char + string(out_str.rbegin(), out_str.rend()); // NOTE: convenient way to reverse a string
    cout << out_str << endl;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    palindrome_reorder(s);
    return 0;
}