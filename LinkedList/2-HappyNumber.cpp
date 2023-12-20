using namespace std;
#include <bits/stdc++.h>

int numberSqrt(int n)
{
    int ans = 0;
    while(n > 0)
    {
        int end = n%10;
        ans += end * end;
        n /= 10;
    }
    return ans;
}

//https://leetcode.com/problems/happy-number/ 
bool isHappy(int n) {
        //let fast and slow pointers be n
        int f = n, s = n;

        do
        {
            s = numberSqrt(s);
            f = numberSqrt(numberSqrt(f));
            if(s==1 || f==1)
            return true;
        } while (f != s);
        
        return false;
}

int main()
{
    //cout<< isHappy(12);
    cout<< isHappy(19);
    return 0;
}