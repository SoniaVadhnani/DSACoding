//Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
//To flip an image horizontally means that each row of the image is reversed.
//For example, flipping [1,1,0] horizontally results in [0,1,1].
//To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
//For example, inverting [0,1,1] results in [1,0,0].

using namespace std;
#include <bits/stdc++.h>

void Flip(vector<vector<int>>& v)
{
    for(vector<int> row : v)
    {
        // reverse this array
        for(int i=0; i<(row.size()+1)/2; i++)
        {
            // swap and invert
            int temp = row[i] ^ 1;
            row[i] = row[row.size()-i-1] ^ 1 ;
            row[row.size()-i-1] = temp;
        }
        for(int i=0;i<row.size();i++)
        cout<<row[i]<<" ";
        cout<< endl;
    }
}

int main()
{
    vector<vector<int>> v = {{1,1,0},{1,0,1},{0,0,0}};
    Flip(v);


    return 0;
}