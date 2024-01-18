#include <iostream>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	int min = N + 1, sum = 0;
	for (int i = M; i <= N; i++) {
		int j = 2;
		for (; j <= i / 2; j++) 
			if (i % j == 0) break;
		if (j == i / 2 + 1) {
			if (i < min) min = i;
			sum += i;
		}
	}
	if (sum == 0) cout << "-1";
	else cout << sum << endl << min;
}