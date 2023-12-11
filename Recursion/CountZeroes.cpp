using namespace std;
#include <bits/stdc++.h>

int count(int n, int c)
{
    if(n==0)
    return c;

    if(n%10 == 0)
    return count(n/10,c+1);

    return count(n/10,c);
}

int countzero(int n)
{
    return count(n,0);
}
int main()
{
    cout<<countzero(0);
    return 0;
}