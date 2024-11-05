#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    map<int, int> freqMap;
    set<int> occurrences;

    for (const auto &num : arr)
    {
        freqMap[num]++;
    }

    for (const auto &entry : freqMap)
    {
        if (!occurrences.insert(entry.second).second)
            return false;
    }

    return true;
}