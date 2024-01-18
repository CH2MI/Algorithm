#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N != 1) {
		int i = 2;
		for (; i <= N; i++) {
			if (N % i == 0) break;
		}
		if (i != N + 1) {
			cout << i << endl;
			N /= i;
		}
		else cout << N << endl;
	}
}