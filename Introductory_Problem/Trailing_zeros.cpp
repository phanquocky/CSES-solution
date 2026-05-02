#include <iostream>
#include <cmath>
using namespace std;

long long log5(long long n)
{
    int result = 0;
    while (n >= 5)
    {
        if (n % 5 != 0)
            break;
        n = n / 5;
        result++;
    }

    return result;
}

int main()
{
    long long n;
    cin >> n;

    int result = 0;
    for (int i = 0; i <= n; i += 5)
    {
        result += log5(i);
    }
    cout << result;
    // long long log = log5(n);
    // // range 1 --> 5^log
    // long long result = 4 * (((log) * (log + 1)) / 2) + log;
    // // range 5^log --> n
    // long long current = pow(5, log);
    // while (current * 5 <= n)
    // {
    //     current *= 5;
    //     result++;
    // }
    // cout << result;
}

// intput is a integer n
// output is tralling zeros in the factorial n!

// ex: n = 1 --> n! = 1 --> output: 0
// ex: n = 4 --> n! = 4! = 1.2.3.4 = 24 --> output: 0

// ex: n = 20 --> n! = 20! = 1.2.3....20 --> output here is 4

// the n! have "x" tralling zeros, it means n! | 10^x
// 30 --> 10 | 30   30 = 3 * 10
// 200 --> 100 | 200   200 = 2 * 100

// because 10 = 2 * 5
// how many 2, 5 factor in n!
// n = 20 --> n! = 1.2.3.4.5.6.7.8.9.10. 20 = 5.10.15.20

// result = n // 5
// 25 = 5.5
// 25.2 //25.3
// 125 = 5.5.5
// n! = 5^k.n' with n' cannot devided by 5

// log = 12
// 5^1 --> 2.5^1 --> 3.5^1 --> 4.5^1 --> 5^5^1 (5^2) -->  2.5^2 --> 3.5^2 --> 4.5^2 --> 5^5^2 (5^3)
// 5^k --> 2.5^k --> 3.5^k --> 4*5^k--> 5^(k+1)
