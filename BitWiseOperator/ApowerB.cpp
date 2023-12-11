using namespace std;
#include <bits/stdc++.h>

int apowerb(int base, int power)
{
    int ans = 1; // as if power = 0, default ans is 1

    while(power > 0)
    {
        if(power & 1 == 1)
        {
            ans = ans * base;
        }

        power = power >> 1;
        base = base * base;
    }
    return ans;
}

int main()
{
    cout<<apowerb(3, 6);
    return 0;
}