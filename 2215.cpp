#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> nums1Unique(nums1.begin(), nums1.end()),
        nums2Unique(nums2.begin(), nums2.end());

    for (int n : nums1)
        nums2Unique.erase(n);
    for (int n : nums2)
        nums1Unique.erase(n);

    vector<int> nums1Result(nums1Unique.begin(), nums1Unique.end()),
        nums2Result(nums2Unique.begin(), nums2Unique.end());

    return {nums1Result, nums2Result};
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    auto result = findDifference(nums1, nums2);

    for (auto &&i : result)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}