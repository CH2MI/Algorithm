#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i;
	int sum = 0;
	for (i = 1; i < N && sum != N; i++) {
		sum = i;
		int a = i;
		while (a > 0) {
			int b = a % 10;
			a -= b;
			a /= 10;
			sum += b;
		}
	}
	if (N != sum) cout << '0';
	else cout << i - 1;
}