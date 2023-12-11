//Given an unsorted integer array nums, return the smallest missing positive integer.
//You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

//Example 1:
// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.
// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.

using namespace std;
#include <bits/stdc++.h>

void swap(vector<int>& nums, int first, int second)
    {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }

int firstMissingPositive(vector<int>& nums) {
    int i = 0;
    while(i<nums.size())
    {
        if(nums[i] > 0 && nums[i] <= nums.size() )
        {
            int correct  = nums[i]-1;
            if(nums[i]!=nums[correct])
            {
                swap(nums, i, correct);
            }
            else i++;
        }
        else
        {
            i++;
        }
    }

    for(i = 0; i< nums.size(); i++)
    {
        if(nums[i] != i+1)
        return i+1;
    }

    return -1;
}

int main()
{
    vector<int> nums = {3,4,-1,1}; //ans 2
    
    cout<< firstMissingPositive(nums);
    return 0;
}