// pattern:  & with 1 or shift operated 1

using namespace std;
#include <bits/stdc++.h>

void oddeven(int n)
{
    if(n&1)
    {
        cout<< "odd";
    }
    else
    cout<< "even";
}

void findithbit(int n, int i)
{
    // & the ith bit only with 1 => mask created by left shifting 1
    cout<< (n & (1 << (i-1)));
}

void powerOfTwo(int n)
{
    // if res is 0 => it is power of 2
    // 1000 & 111 => 0000
    cout << (n & (n-1)); // note: fix for n=0, if so, return false. n=0 exception case.
}

void RightMostSetBit(int n)
{
    cout << (n&(-n));
}

int hammingWeight(uint32_t n) {
        int count = 0;
        // while(n > 0)
        // {
        //     count++;
        //     n = n - (n&(-n));
        // }

        while(n>0)
        {
            if(n&1==1)
            count++;
            n = n>>1;
        }
        return count;
    }

int main()
{
    //oddeven(5);
    //findithbit(16, 3);
    //powerOfTwo(15);
    //RightMostSetBit(16);
    //cout<<hammingWeight(5); // number of set bits
    // cout << bitset<8>(5);
    return 0;
}