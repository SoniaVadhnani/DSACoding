using namespace std;
#include <bits/stdc++.h>

void PP1(int n)
{
//     1
//    212
//   32123
//  4321234
// 543212345

    for(int row = 1; row <= n; row++)
    {
        int totalSpace = row > n? row - n: n-row;
        
        //cout << "Total star = " << totalStar<< endl;
        //space
        for(int col = 1; col <= n - row ; col++)
        {cout << " ";}
        //number
        int value = row;
        bool set = false;
        for(int col = 1; col <= 2*row - 1; col++)
        {
            if(value == 1)
            set = true;
            if(set)
            {
                cout<<value++;
            }
            else
            cout<<value--;
        }
        cout<<endl;
    }
}

void PP2(int n)
{
//     1
//    212
//   32123
//  4321234
// 543212345
//  4321234
//   32123
//    212
//     1

    for(int row = 1; row < 2*n; row++)
    {
        int totalSpace = row > n? row - n: n-row;
        int c = row > n? 2*n - row: row;
        //cout << "Total star = " << totalStar<< endl;
        //space
        for(int sp = 1; sp <= totalSpace ; sp++)
        {cout << "  ";}
        //number

        for(int col = c; col >= 1 ; col--)
        {
            cout<< col << " ";
        }
        for(int col = 2; col <= c ; col++)
        {
            cout << col << " ";
        }

        cout<<endl;
    }
}

void PP3(int n)
{
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444

    for(int row = 0; row < 2*n-1; row++)
    {
        for(int col = 0; col < 2*n-1; col++)
        {
            int ans = n-min(min(row,col), min(2*n-row-2, 2*n-col-2));
            cout<<ans;
        }

        cout<<endl;
    }
}

int main()
{
    //PP1(5);
    //PP2(5);
    PP3(4);
    return 0;
}