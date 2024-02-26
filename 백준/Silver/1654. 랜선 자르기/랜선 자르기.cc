#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(vector<int>& v, long long k, int N) {
	long long cnt = 0;
	for (auto i : v) {
		cnt += i / k;
	}

	if (cnt >= N) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	vector<int> v(K);
	for (int i = 0; i < K; i++) {
		cin >> v[i];
	}

	long long start = 1;
	long long end = *max_element(v.begin(), v.end());
	long long ans = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;

		if (solve(v, mid, N)) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans;
}