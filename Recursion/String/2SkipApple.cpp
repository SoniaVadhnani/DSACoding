using namespace std;
#include <bits/stdc++.h>

string skipapple(string str)
{
    if(str.length() == 0)
    {
        return "";
    }

    string out = str.substr(0, 5);
    if(out == "apple")
    {
        return skipapple(str.substr(5));
    }
    return str[0] + skipapple(str.substr(1));
}

string skipappNotapple(string str)
{
    if(str.length() == 0)
    {
        return "";
    }

    //string out = str.substr(0, 5);
    if(str.substr(0, 3)=="app")
    {
        if(str.substr(0, 5) == "apple")
        {
            return str.substr(0, 5) + skipappNotapple(str.substr(5));
        }
        else{
            return skipappNotapple(str.substr(3));
        }
    }
     
    return str[0] + skipappNotapple(str.substr(1));
}

int main(){
    string str = "bdappapplez";
    //cout<<skipapple(str);
    cout<<skipappNotapple(str);
    return 0;
}