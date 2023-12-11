using namespace std;
#include <bits/stdc++.h>

void printPermutation(string pro, string up)
{
    if(up=="")
    {
        cout<<pro<<endl;
        return;
    }

    for(int i=0; i<= pro.length(); i++)
    {
        string s = pro.substr(0,i) + up[0] + pro.substr(i);
        printPermutation(s, up.substr(1));
    }
}

vector<string> RetPermutation(string pro, string up)
{
    vector<string> ans;
    if(up=="")
    {
        ans.push_back(pro);
        return ans;
    }

    for(int i=0; i<= pro.length(); i++)
    {
        string str = pro.substr(0,i) + up[0] + pro.substr(i);
        vector<string> ret = RetPermutation(str, up.substr(1));
        ans.insert(ans.end(), ret.begin(), ret.end());
    }
    return ans;
}

int PermCount(string pro, string up)
{
    
    if(up=="")
    {
       return 1;
    }
    int count = 0;
    for(int i=0; i<= pro.length(); i++)
    {
        string str = pro.substr(0,i) + up[0] + pro.substr(i);
        count = count + PermCount(str, up.substr(1));
    }
    return count;
}

int main()
{
    //printPermutation("","abc");
    vector<string> ans = RetPermutation("", "abc");
    for(string i:ans)
    {
        cout<<i<<endl;
    }
    cout<<PermCount("", "abc");
    return 0;
}