using namespace std;
#include <bits/stdc++.h>

// 1 -> abc -> 0,1,2
// 2 -> def -> 3,4,5
// 3 -> ghi -> 6,7,8
// 4 -> jkl -> 9,10,11
// 5 -> mno -> 12,13,14
// 6 -> pqr -> 15,16,17
// 7 -> stu -> 18,19,20
// 8 -> vwx -> 21,22,23
// 9 -> yz  -> 24,25

void phonepadcomb(string p, string up)
{
    if(up == "")
    {
        cout<< p << " "; 
        return;
    }

    int digit = up[0] - '0';
    for(int i = (digit-1)*3; i< digit*3 && i<26; i++)
    {
        char newEle = i + 'a';
        phonepadcomb(p + newEle, up.substr(1));
    }
}

vector<string> phonepadcombRet(string p, string up)
{
    if(up == "")
    {
        vector<string> ans = {p};
        return ans;
    }

    vector<string> ans;
    int digit = up[0] - '0';
    for(int i = (digit-1)*3; i< digit*3 && i<26; i++)
    {
        char newEle = i + 'a';
        vector<string> res = phonepadcombRet(p + newEle, up.substr(1));
        ans.insert(ans.end(), res.begin(), res.end());
    }
    return ans;
}

int CountOfCOmb(string p, string up)
{
    if(up == "")
    {
        return 1;
    }

    int ans = 0;
    int digit = up[0] - '0';
    for(int i = (digit-1)*3; i< digit*3 && i<26; i++)
    {
        char newEle = i + 'a';
        ans += CountOfCOmb(p + newEle, up.substr(1));
    }
    return ans;
}

int main()
{
    //phonepadcomb("", "123");

    // for(string i : phonepadcombRet("","12"))
    // {
    //     cout<< i << " ";
    // }

    cout<<CountOfCOmb("", "123");
    return 0;
}