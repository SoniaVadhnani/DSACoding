using namespace std;
#include <bits/stdc++.h>

// matrix - size
// reach from (0,0) => (size-1,size-1)
// only allowed to go right and down
// meaning either x inc or y
int routes(int x, int y, int n)
{
    if(x>n || y>n)
    return 0;
    if(x==n && y==n)
    {
        return 1;
    }

    return routes(x+1,y,n) + routes(x,y+1,n);
} 

int kkroutes(int x, int y)
{
    // if reaches end, there is only one path to corner
    if(x==1 || y==1)
    return 1;

    return kkroutes(x-1,y) + kkroutes(x,y-1);
}

// Print the path => same permutation => processed and unprocessed
void printPath(string p, int x, int y)
{
    if(x==y && y==1)
    {
        cout<<p<<" ";
        return;
    }

    if(x>1) // can go down
    printPath(p+'D', x-1, y);

    if(y>1) // can go right
    printPath(p+'R', x, y-1);
}

vector<string> RetPath(string p, int x, int y)
{
    vector<string> ans;
    if(x==y && y==1)
    {
        ans.push_back(p);
        return ans;
    }

    // for diagonal path
    if(x>1 && y>1)
    {
        vector<string> dia = RetPath(p+'d', x-1, y-1);
    ans.insert(ans.end(), dia.begin(), dia.end());
    }

    if(x>1) // can go down
    {vector<string> left = RetPath(p+'D', x-1, y);
    ans.insert(ans.end(), left.begin(), left.end());
    }

    if(y>1) // can go right
    {vector<string> right = RetPath(p+'R', x, y-1);
    ans.insert(ans.end(), right.begin(), right.end());}

    return ans;
}


int main()
{
    //cout << routes(0,0,2);
    //cout<< kkroutes(3,3)<<endl;
    //printPath("",3,3);

    vector<string> res = RetPath("",3,3);
    for(string s: res)
    cout<< s<<endl;
    return 0;
}