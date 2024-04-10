//The sum of squares of Fibonacci numbers up to n is equal to the product of the nth Fibonacci number and the (n+1)th Fibonacci number. 
//This property can be used to calculate the sum of squares of Fibonacci numbers efficiently.
#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_sum_squares_fast(long long n) {
    n = n % 60;  // Pisano period for 10 is 60

    if (n <= 1)
        return n;

    long long a = 0;
    long long b = 1;

    // Calculate the n-th and (n+1)-th Fibonacci numbers
    for (long long i = 2; i <= n + 1; ++i) {
        long long c = (a + b) % 10;
        a = b;
        b = c;
    }

    // The sum of squares of Fibonacci numbers up to n is equal to Fn * Fn+1
    return (a * b) % 10;
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
