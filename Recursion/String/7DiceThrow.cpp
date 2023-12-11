using namespace std;
#include <bits/stdc++.h>
// dice with possibility of occurence of 1,2,3,4,5,6
// form combinations for get a number
// number we want should be less or == to target

void dicethrow(string p, int target)
{
    if(target == 0)
    {
        cout<<p<<endl;
        return;
    }

    for(int i=1; i<=6 && i<=target; i++)
    {

        dicethrow(p + to_string(i), target - i);
    }
}

vector<string> dicethrowRet(string p, int target)
{
    vector<string> ans;
    if(target == 0)
    {
        ans.push_back(p);
        return ans;
    }

    for(int i=1; i<=6 && i<=target; i++)
    {
        vector<string> ret = dicethrowRet(p + to_string(i), target - i);
        ans.insert(ans.end(), ret.begin(), ret.end());
    }
    return ans;
}

// count will be covered in dp?

// any face dice
vector<string> diceface(string p, int target, int face)
{
    vector<string> ans;
    if(target == 0)
    {
        ans.push_back(p);
        return ans;
    }

    for(int i=1; i<= face && i<=target; i++)
    {
        vector<string> ret = diceface(p + to_string(i), target - i, face);
        ans.insert(ans.end(), ret.begin(), ret.end());
    }
    return ans;
}


int main()
{
    //dicethrow("",4);
    
    // vector<string> ans = dicethrowRet("", 4);
    // for(string i:ans)
    // cout<<i<<endl;

    vector<string> ans = diceface("", 8, 8);
    for(string i:ans)
    cout<<i<< " ";
    return 0;
}