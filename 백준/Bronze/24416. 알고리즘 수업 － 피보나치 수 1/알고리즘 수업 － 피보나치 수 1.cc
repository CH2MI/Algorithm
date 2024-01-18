#include <iostream>
using namespace std;

int* f;
int c1 = 0, c2 = 0;;

int fib(int n) {
	if (n == 1 || n == 2) {
		c1++;
		return 1;
	}
	else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		c2++;
	}
	return f[n];
}

int main() {
	int n;
	cin >> n;
	f = new int[n + 1];
	fib(n);
	fibonacci(n);
	cout << c1 << ' ' << c2;
	delete[] f;
}