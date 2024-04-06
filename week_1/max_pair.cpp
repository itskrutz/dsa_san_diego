#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int l1=0;
    long long max1 =numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > max1) {
            max1 = numbers[i];
            l1=i;                  
        }
    }
    for (int i=0; i<n; i++){
        if(i!=l1 && numbers[i]*max1>max_product){
            max_product = numbers[i]*max1;
        }
    }
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
