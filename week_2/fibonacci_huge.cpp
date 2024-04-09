#include <iostream>
//PISANO PERIOD LOGIC. FUN.

// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % m;
// }

unsigned long long pisano_period(unsigned long long m){
    unsigned long long a = 0, b = 1, c = a + b;
    //m*m will not work for all cases of larger numbers.
    for(unsigned long long i = 0; i < 6 * m; i++){
        c = (a + b) % m;
        a = b;
        b = c;
        if(a == 0 && b == 1){
            return i + 1;
        }
    }
    return 0;
}

unsigned long long get_fibonacci_huge_fast(unsigned long long n, unsigned long long m) {
    if (n <= 1)
        return n;

    unsigned long long remainder = n % pisano_period(m);

    unsigned long long previous = 0;
    unsigned long long current  = 1;

    for (unsigned long long i = 0; i < remainder - 1; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;

    }

    return current % m;
}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}