#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, T;
	cin >> N >> T;
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a > T) cnt += a - T;
		else if (T % a != 0) {
			int mn = 10000;
			for (int i = 1; i <= T; i++) {
				if (T % i == 0) mn = min(mn, abs(i - a));
			}
			cnt += mn;
		}
	}

	cout << cnt;
} 