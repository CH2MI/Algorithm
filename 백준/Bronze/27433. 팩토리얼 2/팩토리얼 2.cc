#include <iostream>
using namespace std;

long long int factorial(long long int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int main() {
	long long int N;
	cin >> N;
	cout << factorial(N);
}