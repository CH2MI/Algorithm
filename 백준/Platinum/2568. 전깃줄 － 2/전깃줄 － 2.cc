#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& A, const int B) {
	return A.first < B;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v(N);
	for (auto& i : v) {
		cin >> i.first >> i.second;
	}
	sort(v.begin(), v.end());

	vector<pair<int, int>> dp;
	dp.push_back({ v[0].second, v[0].first });
	vector<int> tracking(N, -1);

	for (int i = 1; i < N; i++) {
		auto itr = lower_bound(dp.begin(), dp.end(), v[i].second, cmp);

		// 길이가 추가될 때
		if (itr == dp.end()) {
			dp.push_back({ v[i].second, i });
			tracking[i] = (dp.rbegin() + 1)->second;
		}

		// 기존 길이를 갱신할 때
		else {
			itr->first = v[i].second;
			itr->second = i;
			if (itr != dp.begin()) {
				tracking[i] = (itr - 1)->second;	
			}
		}
	}

	vector<bool> del(N, true);
	int i = dp.rbegin()->second;
	while (i != -1) {
		del[i] = false;
		i = tracking[i];
	}

	cout << N - dp.size() << '\n';
	for (int i = 0; i < N; i++) {
		if (del[i]) {
			cout << v[i].first << '\n';
		}
	}
}