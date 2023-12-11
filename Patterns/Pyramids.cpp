using namespace std;
#include <bits/stdc++.h>

void halfPyramid(int n)
{
// *
// **
// ***
// ****
// *****
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {cout << "*";}

        cout<<endl;
    }
}

void invertedHalfPyramid(int n)
{
// *****
// ****
// ***
// **
// *
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= n-row+1; col++)
        {cout << "*";}

        cout<<endl;
    }
}

void halfDiamond(int n)
{
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {cout << "*";}

        cout<<endl;
    }
    for(int row = 1; row < n; row++)
    {
        for(int col=1 ; col<= n-row ; col++)
        {cout << "*";}

        cout<<endl;
    }
}

void halfDiamondKK(int n)
{
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
    for(int row = 1; row < 2*n; row++)
    {
       int totalColsInRow = row > n ? 2*n - row : row ;
        for(int col = 1; col <= totalColsInRow; col++)
        {cout << "*";}

        cout<<endl;
    }
}

int main()
{
    //halfPyramid(5);
    //invertedHalfPyramid(5);
    //halfDiamond(5);
    halfDiamondKK(5);
    return 0;
}