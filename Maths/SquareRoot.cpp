// Three ways covered here, 
// 1 - Brute force
// 2 - Binary search
// 3 - Newton Raphson Method

using namespace std;
#include <bits/stdc++.h>

void squreRoot(int n)
{
    int i = 2;
    while(i*i<=n)
    {
        i++;
    }
    cout<<(i-1)<<endl;
}

// O(log n)
double BinarySearchSquareRoot(int n, int d)
{
    int s=0, e=n;
    double root = 0.0;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        //cout<< " mid = " <<mid;
        if(mid*mid == n)
        {
            return mid;
        }

        if(mid*mid > n)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    root = e;
    //cout<< "root = "<<e<<endl;
    double incr = 0.1;
    // in case of 40, s and e both are at 6 which is clearly not the ans.
    // now we will increment for precision

    for( int i=0; i<d ; i++)
    {
        while(root * root <= n)
        {
            root += incr;
        }
        // condition break meaning root * root > n, go back 1 incr
        root -= incr;
        incr /= 10; //here 0.1 => 0.01 => 0.001
    }

    return root;
    

}

double NewtonSquareRoot(int n)
{
    double x = n;
    double root;
    // loop will break if error < 1
    while(true)
    { 
        root = 0.5 * (x + (n/x));
        if(abs(x-root)< 0.5)
        break;

        x=root;
    }

    return root;
}

int main()
{
    int n = 40;
    // squreRoot(n);
    // int d = 3;  // number of decimals precision needed
    // cout<<BinarySearchSquareRoot(n,d);

    cout << NewtonSquareRoot(n);
    return 0;
}