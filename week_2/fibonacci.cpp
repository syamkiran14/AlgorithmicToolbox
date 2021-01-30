#include <iostream>

long long int fibonacci_naive(long long int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int main(){
	long long int n;
	std::cin>>n;
	std::cout<<fibonacci_naive(n);
}
