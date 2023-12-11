using namespace std;
#include<bits/stdc++.h>

// ****
// ***
// **
// *
void p1(int r, int c)
{
    if(r==0)
    return;

    if(c<r)
    {
        cout<<"*";
        p1(r,c+1);
    }
    else
    {
        cout<<endl;
        p1(r-1,0);
    }
}

// *
// **
// ***
// ****
void p2(int r, int c)
{
    if(r==0)
    return;

    if(c<r)
    {
        p2(r,c+1);
        cout<<"*";
    }
    else
    {
        p2(r-1,0);
        cout<<endl;
    }
}

int main()
{
    p2(4,0);
    return 0;
}