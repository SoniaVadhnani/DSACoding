//Given an array nums of n integers where nums[i] is in the range [1, n], 
//return an array of all the integers in the range [1, n] that do not appear in nums.

using namespace std;
#include <bits/stdc++.h>

vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        // cyclic sort
        while(i < nums.size())
        {
            int correctIndex = nums[i]-1;

            // this comparison is important
            if(nums[i] != nums[correctIndex])
            {
                //swap
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            }
            else
            {
                i++;
            }
        }

        //check sorted array and pushback missing numbers
        for(i = 0; i< nums.size(); i++)
        {
            if(nums[i] != i+1)
            ans.push_back(i+1);
        }
        return ans;
    }


int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1}; //ans 5,6
    nums = findDisappearedNumbers(nums);
    for(int num : nums)
    {
        cout<< num << " ";
    }
    return 0;
}