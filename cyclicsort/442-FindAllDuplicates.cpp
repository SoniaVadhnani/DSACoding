//Given an integer array nums of length n where all the integers of nums are in the range [1, n] 
//and each integer appears once or twice, return an array of all the integers that appears twice.
//You must write an algorithm that runs in O(n) time and uses only constant extra space.

using namespace std;
#include <bits/stdc++.h>

vector<int> findDuplicates(vector<int>& nums) {
    int i=0;
    vector<int> ans;
    while(i < nums.size())
    {
        int correctIndex = nums[i]-1;
        if(nums[i] != nums[correctIndex])
        {
            int temp = nums[i];
            nums[i] = nums[correctIndex];
            nums[correctIndex] = temp;
        }
        else
        {
            i++;
        }
    }

    for(i = 0;i<nums.size();i++)
    {
        if(nums[i] != i+1)
        ans.push_back(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,1,2}; //ans 1
    // {4,3,2,7,8,2,3,1} //ans {2,3}
    nums = findDuplicates(nums);
    for(int num : nums)
    {
        cout<< num << " ";
    }
    return 0;
}