#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

long long recursion(int l, int r) {
	if (l == r) return v[l];

	int mid = (l + r) / 2;

	// 왼쪽 구역의 최댓값
	long long L = recursion(l, mid);

	// 오른쪽 구역의 최댓값
	long long R = recursion(mid + 1, r);

	int i = mid;
	int j = mid;
	int m = v[mid];
	long long sum = v[mid];

	// 중앙을 포함했을 때 최댓값
	while (i > l && j < r) {
		if (v[i - 1] < v[j + 1]) {
			++j;
			m = min(v[j], m);
		}
		else {
			--i;
			m = min(v[i], m);
		}
		sum = max(sum, (long long)m * (j - i + 1));
	}

	while (i > l) {
		--i;
		m = min(v[i], m);
		sum = max(sum, (long long)m * (j - i + 1));
	}

	while (j < r) {
		++j;
		m = min(v[j], m);
		sum = max(sum, (long long)m * (j - i + 1));
	}

	/*cout << l << ' ' << r << ':';
	cout << L << ' ' << R << ' ' << sum << '\n';*/

	return max({ L, R, sum });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	int n;
	cin >> n;

	v.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << recursion(0, n - 1) << '\n';

}