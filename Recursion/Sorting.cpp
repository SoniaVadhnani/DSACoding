using namespace std;
#include <bits/stdc++.h>

void bubble(int arr[],int r, int c)
{
    if(r==0)
    return;

    if(c<r)
    {
        if(arr[c]>arr[c+1])
        {
            //swap
            int temp = arr[c];
            arr[c] = arr[c+1];
            arr[c+1] = temp;
        }
        bubble(arr,r,c+1);
    }
    else
    {
        bubble(arr,r-1,0);
    }
}

void selection(int arr[], int r, int c, int mi)
{
     if(r==0)
     return;

     if(c<r)
     {
        if(arr[mi]<arr[c])
        {
            //update max index
            mi = c;
        }
        selection(arr, r, c+1, mi);
     }
     else
     {
        // swap as we are done finding mi for current round
        int temp = arr[mi];
        arr[mi] = arr[r-1];
        arr[r-1] = temp;
        selection(arr, r-1, 0, 0);
     }
}

void mergeArrays(int arr1[], int arr2[])
{
    
}

int main()
{
    int arr[] = {4,3,2,1};
    //bubble(arr,3,0);
    selection(arr, 4, 0, 0);
    for(int i = 0;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}