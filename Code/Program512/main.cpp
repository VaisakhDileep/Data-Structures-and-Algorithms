/*
Created by  : Vaisakh Dileep
Date        : 5, December, 2021
Description : This program finds the modulo multiplicative inverse(brute force approach).
*/

#include<iostream>

using namespace std;

// Inorder to understand modulo multiplicative inverse refer "Data Structures and Algorithms Manual 1" pg no:11.

/*
Convention used:
    a * X (congruent to) 1(mod p), where 'X' is the modulo multiplicative inverse
*/

long long modulo_multiplicative_inverse(long long a, long long p)
{
    for(int X {1}; X < p; X++)
    {
        if(((a % p) * (X % p)) % p == 1)
        {
            return X;
        }
    }

    throw string {"ERROR - Invalid operation, 'a' and 'p' should be relative primes in order to calculate modulo multiplicative inverse ....."};
}

long long handle_modulo_multiplicative_inverse(long long a, long long p)
{
    try
    {
        return modulo_multiplicative_inverse(a, p);
    }
    catch(string &ex)
    {
        cout<<ex;

        return LLONG_MIN; // This is returned in case if we fail to calculate modulo multiplicative inverse.
    }
}

int main()
{
    cout<<"modulo_multiplicative_inverse(10, 3): "<<handle_modulo_multiplicative_inverse(10, 3)<<"\n";

    cout<<"modulo_multiplicative_inverse(10, 7): "<<handle_modulo_multiplicative_inverse(10, 7)<<"\n";

    cout<<"modulo_multiplicative_inverse(10, 4): "<<handle_modulo_multiplicative_inverse(10, 4)<<"\n"; // We can't find modulo multiplicative inverse if 'a' and 'p' are not relatively prime.

    cout<<"modulo_multiplicative_inverse(7, 4): "<<handle_modulo_multiplicative_inverse(7, 4)<<"\n";

    return 0;
}