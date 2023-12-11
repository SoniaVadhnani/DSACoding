using namespace std;
#include <bits/stdc++.h>

// passing the answer string in arguement
void skipchar(string input, string output)
{
   if(input == "")
   {cout<<output;
   return;
   }

   if(input[0]=='a')
   {
    skipchar(input.substr(1), output);
   }

    else{
        skipchar(input.substr(1), output+input[0]);
    }
}


// create the answer variable in function boday
string skipchar(string input, int cur)
{
    if(input[cur] == '\0')
    return "";

    if(input[cur] == 'a')
    return skipchar(input, cur+1);

    return input[cur]+skipchar(input,cur+1);

}

int main(){

string s = "abcccaabccc";
    cout<<skipchar(s,0)<<endl;
    string str;
    skipchar(s,str);
    return 0;
}