using namespace std;
#include <bits/stdc++.h>

// just printing
void SubSeq(string p, string up)
{
    if(up=="")
    {
        cout<<p<< " , ";
        return;
    }
    SubSeq(p, up.substr(1));
    SubSeq(p+up[0], up.substr(1));
    
}

// returning the array of the subsets
// one approach easy is passing in the arguement, add whenever we reach base condition.
// intersting is doing in function body and returning
vector<string> subseq(string p, string up)
{
    if(up=="")
    {
        vector<string> ans = {p};
        return ans;
    }
    vector<string> a= subseq(p, up.substr(1));
    vector<string> b = subseq(p+up[0], up.substr(1));
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void subseqWithAscii(string p, string up)
{
    if(up=="")
    {
        cout<<p<<endl;
        return;
    }
    subseqWithAscii(p, up.substr(1));
    subseqWithAscii(p+up[0], up.substr(1));
    subseqWithAscii(p+to_string(up[0]+0), up.substr(1));

}

vector<string> subseqAsciiReturn(string p, string up)
{
    if(up=="")
    {
        vector<string> ans ={p};
        return ans;
    }
    vector<string> a =subseqAsciiReturn(p, up.substr(1));
    vector<string> b =subseqAsciiReturn(p+up[0], up.substr(1));
    vector<string> c =subseqAsciiReturn(p+to_string(up[0]+0), up.substr(1));
    a.insert(a.end(), b.begin(), b.end());
    a.insert(a.end(), c.begin(), c.end());
    return a;
}

int main()
{
    //SubSeq("","abc");

    // for(string i : subseq("","abc"))
    // {
    //     cout<<i<<endl;
    // }

    //subseqWithAscii("", "ab");
    for(string i : subseqAsciiReturn("","abc"))
    {
        cout<<i<<"  ";
    }

    return 0;
}