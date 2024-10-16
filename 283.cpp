#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    // int n = nums.size();

    // // Count the zeroes
    // int numZeroes = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     numZeroes += (nums[i] == 0);
    // }

    // // Make all the non-zero elements retain their original order.
    // vector<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     if (nums[i] != 0)
    //     {
    //         ans.push_back(nums[i]);
    //     }
    // }

    // // Move all zeroes to the end
    // while (numZeroes--)
    // {
    //     ans.push_back(0);
    // }

    // // Combine the result
    // for (int i = 0; i < n; i++)
    // {
    //     nums[i] = ans[i];
    // }

    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
    
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
    {
        nums[i] = 0;
    }

    // for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++)
    // {
    //     if (nums[cur] != 0)
    //     {
    //         swap(nums[lastNonZeroFoundAt++], nums[cur]);
    //     }
    //     for (auto &&i : nums)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (size_t i = 0; i < nums.capacity(); i++)
    {
        cout << nums[i] << " ";
    }
}