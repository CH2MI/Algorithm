#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	sort(v.begin(), v.end());

	int l = 0, r = N - 1;
	int mn = abs(v[l] + v[r]), L = l, R = r;

	while (l < r) {
		int sum = v[l] + v[r];
		if (abs(sum) < mn) {
			L = l;
			R = r;
			mn = abs(sum);
		}

		if (sum <= 0) l++;
		if (sum >= 0) r--;
	}
	cout << v[L] << ' ' << v[R];
}