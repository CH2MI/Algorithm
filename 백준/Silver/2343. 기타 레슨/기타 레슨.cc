#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int mxcnt;

bool solve(int mid) {
	int cnt = 1;
	int sum = 0;

	for (const auto& i : v) {
		if (sum + i <= mid) {
			sum += i;
		}
		else {
			cnt++;
			sum = i;
		}
	}
	return cnt <= mxcnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N >> mxcnt;
	v = vector<int>(N);

	for (auto& i : v) cin >> i;

	int lo = *max_element(v.begin(), v.end()) - 1, hi = (int)1e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) hi = mid;
		else lo = mid;
	}

	cout << hi << '\n';
}