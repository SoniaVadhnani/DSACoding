using namespace std;
#include <bits/stdc++.h>

void cyclicSortArr(int arr[], int n)
{
    // check current pos
    // swap if wrong index => correct index (repeat until current is correct index)
    // move only if current is correct position

    for(int i = 0; i < n; )
    {
        if(arr[i] == i+1)
        {
            i++;
        }
        else{
            int temp = arr[arr[i]-1];
            arr[arr[i]-1] = arr[i];
            arr[i] = temp;
        }
    }

}



void swap(int arr[], int firstIndex, int secondIndex)
{
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

void print(int arr[], int n)
{
    for(int i  = 0 ;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {3,5,2,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cyclicSortArr(arr, n);
    print(arr, n);
    return 0;
}