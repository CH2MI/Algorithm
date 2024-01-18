#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int n, count = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (i == 1) continue;
			int j;
			for (j = 2; j * j <= i; j++) {
				if (i % j == 0) break;
			}
			if (j * j > i) count++;
		}
		cout << count << '\n';
	}
}