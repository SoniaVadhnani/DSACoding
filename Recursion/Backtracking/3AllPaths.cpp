using namespace std;
#include <bits\stdc++.h>

// just 2 lines added, mark and unmark

vector<string> AllPaths(string p, vector<vector<bool>> maze, int x, int y)
{
    vector<string> ans;
    if(x== maze.size()-1 && y== maze[0].size()-1)
    {
        ans.push_back(p);
        return ans;
    }

    if(!maze[x][y])
    {
       // ans.push_back("");
        return ans;
    }

    // i am considering this block in my path
    maze[x][y] = false;
    

    if(x < maze.size()-1) // can go down
    {vector<string> left = AllPaths(p+'D',maze, x+1, y);
    ans.insert(ans.end(), left.begin(), left.end());
    }

    if(y < maze[0].size()-1) // can go right
    {vector<string> right = AllPaths(p+'R',maze, x, y+1);
    ans.insert(ans.end(), right.begin(), right.end());}

    if(x > 0) // can go Up
    {vector<string> up = AllPaths(p+'U',maze, x-1, y);
    ans.insert(ans.end(), up.begin(), up.end());}

    if(y > 0) // can go left
    {vector<string> left = AllPaths(p+'L',maze, x, y-1);
    ans.insert(ans.end(), left.begin(), left.end());}

    // as recursion calls are done
    // this is where function will be over so unmark the cell as block
    // as this fn will be removed, also remove the changes made by the fn
    maze[x][y] = true;

    return ans;
}

int main()
{
    vector<vector<bool>> maze = {
    {true, true, true},
    {true, true, true},
    {true, true, true}};

    vector<string> ans = AllPaths("", maze, 0,0);
    for(string s:ans)
    cout<< s << " ";

    return 0;}