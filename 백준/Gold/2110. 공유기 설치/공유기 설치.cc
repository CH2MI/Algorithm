#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(vector<int>& dif, int D, int C) {
	int cnt = 1;
	int s = 0;
	for (auto i : dif) {
		s += i;
		if (s >= D) {
			++cnt;
			s = 0;
		}
	}
	if (cnt < C) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	vector<int> dif(N - 1);
	for (int i = 0; i < N - 1; i++) {
		dif[i] = v[i + 1] - v[i];
	}
	
	int start = 1;
	int end = v[N - 1];
	int ans = 0;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (solve(dif, mid, C)) {
			start = mid + 1;
			ans = mid;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans;
}