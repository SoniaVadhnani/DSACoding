using namespace std;
#include <bits/stdc++.h>

void Diamond(int n)
{
//   *
//  ***
// *****
//  ***
//   *
int totalStar = -1;
    for(int row = 1; row < 2*n; row++)
    {
        int totalSpace = row > n? row - n: n-row;
        totalStar = row > n? totalStar - 2: totalStar + 2;
        //cout << "Total star = " << totalStar<< endl;
        //space
        for(int col = 1; col <= totalSpace ; col++)
        {cout << " ";}
        //star
       for(int col = 1; col <= totalStar; col++)
        {cout << "*";}

        cout<<endl;
    }
}

void DiamondWithSpace(int n)
{
//     *
//    * *
//   * * *
//  * * * *
// * * * * * 
//  * * * *
//   * * *
//    * *
//     * 

for(int row = 1; row < 2*n; row++)
{
    int totalCol = row > n? 2*n - row: row;
    int totalSpaces = n - totalCol;

    for(int sp = 1; sp <= totalSpaces; sp++)
    {
        cout << " ";
    }

    for(int st = 1; st <= totalCol; st++)
    {
        cout << "* ";
    }
    cout<<endl;
}

}

int main()
{
    //Diamond(5);
    DiamondWithSpace(5);
    return 0;
}