using namespace std;
#include <bits/stdc++.h>

// helping function with recursion
int twostacks(int x, vector<int> a, vector<int> b, int sum, int count)
{
    if(sum > x)
    {
        return count;
    }

    // if any of array is empty, cant go further
    if(a.size() == 0 || b.size()==0)
    return count;

    // when element is taken from a vector
    vector<int> v1(a.begin()+1, a.end());
    int ans1 = twostacks(x, v1, b, sum + a[0], count+1);

    // when element is taken from b vector
    vector<int> v2(b.begin()+1, b.end());
    int ans2 = twostacks(x, a, v2, sum + b[0], count+1);

    // maximum of both
    return max(ans1,ans2);

}

int twostacks(int x, vector<int> a, vector<int> b)
{
    // as extra element gives value more then required, so reduce one element
    return twostacks(x,a,b,0,0) - 1;
}

int main()
{
    vector<int> a = {4,2,4,6,1};
    vector<int> b = {2,1,8,5};
    int sum = 10;
    cout << twostacks(10, a, b);
    return 0;
}