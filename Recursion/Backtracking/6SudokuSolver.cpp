using namespace std;
#include <bits/stdc++.h>

void display(vector<vector<bool>> board)
{
    for(vector<bool> row : board)
    {
    for(bool cell: row)
    {
        if(cell)
        cout<<"K ";
        else
        cout<<"- ";
    }
        cout<<endl;
    }
    cout<<endl;
}


bool isSafe(vector<vector<bool>> board, int row, int col, int num)
{
    
    // check for row
    for(int i=0; i<board.size(); i++)
    {
        // check if num is in the row
        if( board[row][i] == num)
            return false;
    }

    // check for col
    for(vector<bool> nums: board)
    {
        // check for each cell in the column
        if(nums[col] == num)
            return false;
    }

    // check for squRE MAtrix
    int sqrrt = sqrt(board.size());
    int rowStart = row - row % sqrrt;
    int colStart = col - col % sqrrt;

    for(int r = rowStart; r < rowStart + sqrrt; r++)
    {
        for(int c = colStart; r < colStart + sqrrt; c++)
        {
            if(board[r][c] == num)
            return false;
        }
    }

    return true;
}

// sudoku puzzle as input and blank spaces as 0
void solve(vector<vector<int>> board)
{
    // complete it later by yourself
}


int main()
{
    int sqrrt = sqrt(10);
    cout<< sqrrt;
    
    return 0;
}