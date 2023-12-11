


using namespace std;
#include <bits/stdc++.h>

// O(n)
void factors1(int n)
{
    for(int i =1; i<=n; i++)
    {
        if(n%i)
        {
            continue;
        }
        cout<< i << " ";
    }
}

// O(sqrt(n))
void factors2(int n)
{
    for(int i =1; i<= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            if(n/i == i)
            cout<< i << " ";
            else 
            cout<< i << " " << n/i << " "; 
        }
    }
}

int main()
{
    
    factors2(36);
    return 0;
}