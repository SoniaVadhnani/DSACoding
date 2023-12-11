using namespace std;
#include <bits/stdc++.h>
// [],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]
vector<vector<int>> subset(vector<int> arr)
{
    vector<vector<int>> ans = {{}}; // first one entry should be there of empty vector

    for(int i: arr)
    {
        int n = ans.size(); // this is imp to be done outside bcz if instead of n we put
                            // ans.size(), it keeps on increasing and it goes till infinite - m/m full
        // as for existing vectors in ans, next letter is added to each vector
        // so the loop will run till size of ans
        for(int a = 0; a < n; a++)
        {
            vector<int> newhalf = ans[a];
            newhalf.push_back(i);
            ans.push_back(newhalf);
        }
    }
    return ans;
}


vector<vector<int>> subsetDupe(vector<int> arr)
{
    vector<vector<int>> ans = {{}}; 
    sort(arr.begin(), arr.end());  // ==> sorting to keep the duplicate elements adjacent
    
    int start = 0, end = 0;

    for(int i=0; i<arr.size(); i++)
    {
        start = 0;
        // if current and previous element is same, s = e+1;
        if(i>0 && arr[i]==arr[i-1])
        {
            start = end + 1;
        }
        end = ans.size() - 1;

        int n = ans.size();
        for (int j = start; j < n; j++)
        {
            vector<int> newhalf = ans[j];
            newhalf.push_back(arr[i]);
            ans.push_back(newhalf);
        }
    }

    return ans;
}

int main()
{
    
    //vector<vector<int>> ans = subset({1,2,3});
    vector<vector<int>> ans = subsetDupe({2,1,2});
    for(auto i: ans)
    {
        cout<<"{";
    
    for(auto j: i)
    {cout<<j;}
    
    cout<<"}"<<endl;
    }
    return 0;
}