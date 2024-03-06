#include <iostream>
using namespace std;

long long comb(long long n) {
	return (n >> 1) * (n - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long N;
	cin >> N;

	long long sum = 1;
	for (long long i = N, j = N / 2; i > 0; i -= 2, j--) {
		sum *= comb(i) / j;
	}

	cout << sum;
}