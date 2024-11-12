#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;
    int count = 0;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == k)
        {
            count++;
            left++;
            right--;
        }
        else if (sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return count;
}

int main()
{
    // 3,1,3,4,3
    vector<int> nums = {1, 2, 3, 6};
    cout << endl
         << maxOperations(nums, 5) << endl;
    return 0;
}