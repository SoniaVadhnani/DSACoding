using namespace std;
#include <bits/stdc++.h>


    static int sum = 0;
int reverse(int n)
{
    if(n==0)
    return 0;
    int rem = n%10;
    sum = sum * 10 + rem;
    //cout<<sum<<endl;
    reverse(n/10);
}

int helper(int n, int digits)
{
    if (n%10 == n)
    return n;

    int rem = n%10;
    return rem * (int)pow(10, digits-1) + helper( n/10 , digits-1);
}

int revreseKK(int n)
{
    int digits = (int)log10(n) + 1;
    cout<<digits<<endl;
    return helper(n, digits);
}

int main()
{
    //reverse(1234);
    //cout<<sum;
    cout<<revreseKK(1234);
    return 0;
}