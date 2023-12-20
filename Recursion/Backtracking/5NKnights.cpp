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

bool isValid(vector<vector<bool>> board, int row, int col)
{
    if(row >=0 && row < board.size() && col >=0 && col < board.size())
    {
        return true;
    }
    return false;
}

bool isSafe(vector<vector<bool>> board, int row, int col)
{
    if(isValid(board, row-2,col-1))
    if(board[row-2][col-1])
    return false;

    if(isValid(board, row-2,col+1))
    if(board[row-2][col+1])
    return false;

    if(isValid(board, row-1,col-2))
    if(board[row-1][col-2])
    return false;

    if(isValid(board, row-1,col+2))
    if(board[row-1][col+2])
    return false;

    return true;
    
}


void knights(vector<vector<bool>> board, int row, int col, int target)
{
    // target 0
    if(target == 0)
    {
        display(board);
        return;
    }

    // skip
    if(row == board.size() - 1 && col == board.size())
    return;

    // if reached end of row => next row
    if(col == board.size())
    {
        knights(board, row + 1, 0, target);
        return;
    }

    if(isSafe(board, row, col))
    {
        board[row][col] = true;
        knights(board, row, col+1, target-1);
        board[row][col] = false;
    }

    knights(board, row, col+1, target);
}


int main()
{
    vector<vector<bool>> board = {
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false}};
    
    knights(board, 0, 0, 4);
    
    return 0;
}