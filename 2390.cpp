#include <iostream>
#include <vector>

using namespace std;

string removeStars(string s)
{
    vector<char> result;

    for (char c : s)
    {
        if (c == '*')
        {
            if (!result.empty())
                result.pop_back();
        }
        else
        {
            result.push_back(c);
        }
    }

    return string(result.begin(), result.end());
}