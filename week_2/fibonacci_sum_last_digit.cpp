#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

// unsigned long long pisano_period(unsigned long long m){
//     unsigned long long a = 0, b = 1, c = a + b;
//     //m*m will not work for all cases of larger numbers.
//     for(unsigned long long i = 0; i < 6 * m; i++){
//         c = (a + b) % m;
//         a = b;
//         b = c;
//         if(a == 0 && b == 1){
//             return i + 1;
//         }
//     }
//     return 0;
// }

//i ran this code and know that the pisano period of 10 is 60. now i can proceed with n mod 10 like in the previous question.

int fibonacci_sum_fast(long long n) {
     long long remainder = n % 60;

        if (remainder <= 1)
            return remainder;
     long long a = 0;
     long long b = 1;
     long long sum=a+b;

    for ( long long i = 0; i < remainder-1 ; ++i) {
        long long c = (a+b);
        a = b;
        b = c;
        sum += c;
    }

    return sum%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout<<pisano_period(n);
    std::cout << fibonacci_sum_fast(n);
}
