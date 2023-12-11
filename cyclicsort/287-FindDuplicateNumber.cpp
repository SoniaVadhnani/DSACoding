//Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
//There is only one repeated number in nums, return this repeated number.
//You must solve the problem without modifying the array nums and uses only constant extra space.

using namespace std;
#include <bits/stdc++.h>

int findDuplicateKK(vector<int>& nums) {
    int i=0;
    
    while(i < nums.size())
    {
        if(nums[i] != i+1)
        {
            // correct index for the value
            int correct = nums[i]-1;
            //value not already present at correct loc
            if(nums[i] != nums[correct])
            {
                //swap
            int temp = nums[i];
            nums[i] = nums[correct];
            nums[correct] = temp;
            }
            else
            {
                return nums[i];
            }
        }
        else
        i++;
    }
return -1;
}


int findDuplicate(vector<int>& nums) {
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
    return nums[nums.size()-1];
}

int main()
{
    vector<int> nums = {1,3,4,2,2}; //ans 2
    cout << findDuplicateKK(nums);
    return 0;
}