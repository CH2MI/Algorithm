#include <iostream>
using namespace std;

long long solve(long long k, long long N) {
	long long cnt = 0;
	for (int i = 1; i <= N; i++) {
		cnt += min(k / i, N);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long N, k;
	cin >> N >> k;
	k = min((long long)1000000000, k);
	long long start = 1;
	long long end = N * N;

	while (start <= end) {
		long long mid = start + (end - start) / 2;
		
		long long cnt = solve(mid, N);

		// 개수가 넘어가면 왼쪽으로 내려간다.
		if (cnt >= k) {
			end = mid - 1;
		}

		// 개수가 부족하면 오른쪽으로 올리간다.
		else {
			start = mid + 1;
		}
	}
	cout << start;
}