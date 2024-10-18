#include <iostream>

using namespace std;

bool isSubsequence(string s, string t)
{
    if (s.length() == 0)
        return true;
        
    int sLength = s.length(),
        tLength = t.length(),
        sPointer = 0,
        tPointer = 0;

    while (tPointer < tLength)
    {
        if (s[sPointer] == t[tPointer])
        {
            sPointer++;
            if (sPointer == sLength)
                return true;
        }
        tPointer++;
    }

    return false;
}

int main()
{
    cout << isSubsequence("ae", "aceaceace") << endl;
    return 0;
}