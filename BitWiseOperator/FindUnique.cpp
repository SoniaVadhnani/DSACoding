using namespace std;
#include <bits/stdc++.h>

void findunique(int arr[], int n)
{
    int ans = 0;
    for(int i = 0; i< n;i++)
    {
        ans ^= arr[i];
    }
    cout<<ans;
}

int XORfromZerotoN(int n)
{
    // n%4 = 0 => n
    // n%4 = 1 => 1
    // n%4 = 2 => n+1
    // n%4 = 3 => 0

    if(n%4 == 0)
    return n;
    if(n%4 == 1)
    return 1;
    if(n%4 == 2)
    return n+1;
    if(n%4 == 3)
    return 0;
}

void XORfromAtoB(int a, int b) 
{
    // xor 0->b and 0->a-1 for range a to b
    cout<< bitset<8>(XORfromZerotoN(b) ^ XORfromZerotoN(a-1));
 
    // this is only for check, will give TLE for large numbers
    int ans = 0;
    for(int i = a; i <= b; i++)
    {
        ans = ans^i;
    }
    cout << ans;
}

int main()
{
    // int arr[] = {2,3,4,1,2,1,3,6,4};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // findunique(arr, n);

    XORfromAtoB(3,9);
    return 0;
}