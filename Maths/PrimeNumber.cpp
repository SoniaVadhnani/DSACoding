using namespace std;
#include <bits/stdc++.h>

bool isPrime(int n)
{
    // instead of O(n), it is O(sqrt(n))
    
    if(n<=1)
    return false;

    int c = 2;
    while(c*c <= n)     // important loop limit
    {
        if(n % c == 0)
        {
            return false;
        }
        c++;
    }
    return true;
}

void sieve(bool primes[], int n)
{
// as all values are false right now, lets consider false meaning prime
// loop till sqrt(n) and make all factors of it as true.

for(int i=2 ; i*i <= n; i++)
{
    // if values is false
    if(! primes[i])
    {
        // all factors of i
        for(int j = i*2; j<=n ; j = j+i)
        {
            primes[j]= true;
        }
    }
}

// print primes => all false values
for(int i=2;i<=n;i++)
{
    if(!primes[i])
    cout<<i<<"  ";
}
}

int main()
{
    // for(int i=1; i<16; i++)  O(n)
    // {
    //     cout<<i << " - " << isPrime(i)<<endl;
    // }

// instead of checking till n, we will create and array and will only check for numbers not factor of any other number
int n = 37;
bool primes[38];
    sieve(primes, n);
    return 0;
}