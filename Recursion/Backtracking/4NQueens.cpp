using namespace std;
#include <bits/stdc++.h>

void display(vector<vector<bool>> board)
{
    for(vector<bool> row : board)
    {
    for(bool cell: row)
    {
        if(cell)
        cout<<"Q ";
        else
        cout<<"X ";
    }
        cout<<endl;
    }
    cout<<endl;
}


bool isSafe(vector<vector<bool>> board, int row, int col)
{
    // check vertical row
    for(int i=0; i<row; i++)
    {
        if(board[i][col])
        return false;
    }

    // check left diag
    int maxLeft = min(row, col);
    for(int i = 1; i<=maxLeft; i++)  // <= is imp
    {
        if(board[row - i][col - i])
        return false;
    }

    // check right diag
    int right = board.size()-1-col;
    int maxRight = min(row, right);
    for(int i = 1; i<=maxRight; i++) // <= is imp
    {
        if(board[row - i][col + i])
        return false;
    }

    return true;
}


int queens(vector<vector<bool>> board, int row)
{
    //base when row goes out of size, then we got one of the solutions
    if(row == board.size())
    {
        display(board);
        return 1;
    }

    int count = 0;

    // placing the queen and checking for every row and col
    for(int col=0 ; col < board.size(); col++)
    {
        // place the queen if it is safe
        if( isSafe(board, row, col))
        {
            board[row][col] = true; 
            // now the row is done, check for below ones => RECURSION
            count = count + queens(board, row+1);

            // ones rec call done, unset the cell value => BACKTRACKING
            board[row][col] = false;
        }
    }

    return count;
}


int main()
{
    vector<vector<bool>> board = {
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false}};
    
    int count = queens(board, 0);
    cout<< count <<endl;
    return 0;
}