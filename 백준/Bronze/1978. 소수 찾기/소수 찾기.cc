#include <iostream>
using namespace std;

int main() {
	int N, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == 1) continue;
		int j = 2;
		for (; j <= n / 2; j++) 
			if (n % j == 0) break;
		if (j == n / 2 + 1) count++;
	}
	cout << count;
} 