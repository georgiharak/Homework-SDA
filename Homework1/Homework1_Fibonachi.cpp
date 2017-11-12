#include <iostream>

using namespace std;

//Recursion  - Fibonacci Series up to n number of terms
int fibR(int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fibR(x-1)+fibR(x-2);
}




//Without recursion , difficulty O(n) - Fibonacci Series up to n number of terms
int fibL(int n)
{
    int t1 = 0 , t2 = 1 , nextTerm = 0;
    for (int i = 1; i <= n; i++)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return nextTerm;

}




//Взех информацията от http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
//Ползват матричното представяне на числата на Фибоначи             ( https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form )
const int MAX = 1000;
int f[MAX] = {0};
int fibMatrix(int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fibMatrix(n) is already computed
    if (f[n])
        return f[n];

    int k = (n % 2 == 1)? (n+1)/2 : n/2;

    // Applyting above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1)? (fibMatrix(k)*fibMatrix(k) + fibMatrix(k-1)*fibMatrix(k-1))
           : (2*fibMatrix(k-1) + fibMatrix(k))*fibMatrix(k);

    return f[n];
}



int main()
{
    int n;
    cout<<"Enter number of fib sequence: ";
    cin>>n;
    cout<<fibL(n)<<" simple liner , using iteration "<<endl;
    cout<<fibR(n)<<" recursion "<<endl;
    cout<<fibMatrix(n)<<" using matrix "<<endl;

     return 0;
}
