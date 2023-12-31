//You have a set of integers s, which originally contains all the numbers from 1 to n. 
//Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
//which results in repetition of one number and loss of another number.

//You are given an integer array nums representing the data status of this set after the error.
//Find the number that occurs twice and the number that is missing and return them in the form of an array.

using namespace std;
#include <bits/stdc++.h>

void swap(vector<int>& nums, int first, int second)
    {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }

vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        while(i<nums.size())
        {
            int correct  = nums[i]-1;
            if(nums[i]!=nums[correct])
            {
                swap(nums, i, correct);
            }
            else
            {
                i++;
            }
        }

        for(i=0;i<nums.size();i++)
        {
            if(nums[i] != i+1)
            return {nums[i],i+1};
        }

        return {};
    }

int main()
{
    vector<int> nums = {1,1}; //ans 1,2
    nums = findErrorNums(nums);
    for(int num : nums)
    {
        cout<<  num << " ";
    }
    return 0;
}