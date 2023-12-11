using namespace std;
#include <bits/stdc++.h>

void obstacle(string p, vector<vector<bool>> maze, int x, int y)
{
    if(x == maze.size()-1 && y==maze[0].size()-1)
    {
        cout<<p<<" ";
        return;
    }

    if(!maze[x][y])
    return;

    if(x< maze.size()-1) // can go down
    obstacle(p+'D',maze, x+1, y);

    if(y < maze[0].size()-1) // can go right
    obstacle(p+'R',maze, x, y+1);
}

int main()
{
    vector<vector<bool>> maze = {{1,1,1},{1,0,1},{1,1,1}};
    obstacle("",maze,0,0);
    return 0;
}