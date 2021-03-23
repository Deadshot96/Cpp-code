# include <iostream>
# include <cstring>
using namespace std;

/* 
    ===> Sieve of Eratosthenes <===
    The sieve of Eratosthenes is one of the most efficient 
    ways to find all primes smaller than n when n is smaller
    than 10 million
*/

void SieveOfErathosthenes(size_t N){
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));

    for (size_t p = 2; p * p <= N; ++p)
        if (primes[p])
            for (size_t i = p * p; i <= N; i += p)
                primes[i] = false;

    for (size_t p = 2; p <= N; ++p)
        if (primes[p])
            cout << p << "\t";

    cout << endl;
}

int main()
{
    cout << "Hello, World!" << endl;
    SieveOfErathosthenes(10000);
    return 0;
}
