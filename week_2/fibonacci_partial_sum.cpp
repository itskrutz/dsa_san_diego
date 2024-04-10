//really liked this program. flexed some brain muscles. sweet.
#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long m, long long n) 
{
    m = m % 60;
    n = n % 60;

    //next two lines brilliantly sensible. i can only wish i was smart enough to be good at all of this
    //i can 0nly try
    //If n is less than m after taking the modulo, it means that n has "wrapped around" to the beginning of the next 60-number cycle.
    //By adding 60 to n, we effectively move n to its correct position in the next cycle, ensuring that the loop runs from m to n as expected, even if n is in the next cycle.
    //This is a common technique used when dealing with operations involving modulo arithmetic and cyclic sequences.
    if (n < m)
        n += 60;

    long long a = 0;
    long long b = 1;
    long long sum = 0;

    for (long long i = 0; i <= n; ++i) {
        if (i >= m)
            sum += a;

        long long c = a;
        a = b;
        b = (b + c) % 10;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
