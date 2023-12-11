using namespace std;
#include <bits/stdc++.h>

void quicksort(int num[], int low, int hi)
{
    if(low>=hi)
    return;

    int s = low;
    int e = hi;
    int mid = s + (e-s)/2;
    int pivot = num[mid];

    //for swapping
    while(s<=e)
    {
        // finding violations
        // also a reason why if its sorted, it will not swap
        // reason why QS is preffered over MS in arrays
        while(num[s]<pivot)
        s++;

        while(num[e]>pivot)
        e--;

        // swap only if
        if(s<=e)
        {
            int temp = num[s];
            num[s] = num[e];
            num[e] = temp;

            s++;
            e--;
        }
    }

    // now pivot is at its correct index, please sort two halves now
    quicksort(num, low, e);
    quicksort(num, s, hi);


}

int main()
{
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);

    // sort(begin(arr),end(arr));
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    
    return 0;
}