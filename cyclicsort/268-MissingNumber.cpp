//Given an array nums containing n distinct numbers in the range [0, n], 
//return the only number in the range that is missing from the array.

using namespace std;
#include <bits/stdc++.h>

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        // cycle sort
        while(i<n)
        {
            int correctIndex = nums[i];
            if(nums[i]<n && nums[i] != i)
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

        //now the array is sorted
        //case1: missing is not n, so check each index
        for(i = 0;i<n;i++)
        {
            if(nums[i]!=i)
            return i;
        }
        //case2: missing num is n
        return n;
    }

int main()
{
    vector<int> nums = {3,0,1};
    cout<< missingNumber(nums);
    return 0;
}