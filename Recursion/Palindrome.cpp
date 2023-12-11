using namespace std;
#include <bits/stdc++.h>

// for number use ReverseANum and then compare n == Reverse(n)

// below is suitable for string or array


bool pal (string n, int s, int e)
{
    if(s>=e)
    return true;

    if(n[s]==n[e])
    return pal(n,++s,--e);

    return false;
}

int main()
{
    int n = 12531;
    string a = to_string(n);
    int len = a.length();
    cout<<pal(a,0,len-1);
    return 0;
}