#include <iostream>
#include <string>

using namespace std;

string makeFancyString(string s)
{
    if (s.length() <= 2)
        return s;

    string result;
    int count = 1;
    result += s[0];

    for (size_t i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            count++;
        else
            count = 1;

        if (count <= 2)
            result += s[i];
    }

    return result;
}

int main()
{
    auto result = makeFancyString("leeetcode");

    cout << result << endl;

    return 0;
}