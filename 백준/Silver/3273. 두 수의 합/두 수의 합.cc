#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, x;
	cin >> n;

	vector<int> v(n);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	cin >> x;

	int l = 0, r = n - 1, cnt = 0;
	while (l < r) {
		int sum = v[l] + v[r];
		if (sum <= x) l++;
		if (sum >= x) r--;
		if (sum == x) cnt++;
	}
	cout << cnt;
}
