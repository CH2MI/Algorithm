#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		int a = 1, b = 1;
		int cnt = 1;

		// a를 우선적으로 일치시킨다.
		while (a != x) {
			a++; cnt++;
			b++;
			if (b > N) b -= N;
		}
		bool f = true;

		// b가 일치할 때까지 b를 증가시킨다.
		while (b != y) {
			b += M;

			// 범위를 벗어나면 보정한다.
			while (b < 0) b += N;
			while (b > N) b -= N;
			cnt += M;

			// 총 횟수를 벗어나면 유효하지 않은 표현이다.
			if (cnt > M * N) {
				f = false;
				break;
			}
		}

		if (f) cout << cnt << '\n';
		else cout << "-1\n";
	}
}