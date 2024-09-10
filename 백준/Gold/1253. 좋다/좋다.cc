#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);

	for (auto& i : v) cin >> i;

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			int value = v[i] - v[j];

			auto itr1 = lower_bound(v.begin(), v.begin() + i, value);
			auto itr2 = lower_bound(v.begin() + i + 1, v.end(), value);

			if (itr1 - v.begin() != i && itr1 - v.begin() != j && itr1 != v.end() && *itr1 == value) {
				cnt++;
				break;
			}
			if (itr2 - v.begin() != i && itr2 - v.begin() != j && itr2 != v.end() && *itr2 == value) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt;
}
