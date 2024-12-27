#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
array<unordered_map<long long, long long>, 2> m;

void bt(int S, int cnt, long long sum, int s, int e, int r) {
	if (S == cnt) {
		m[r][sum]++;
		return;
	}

	for (int i = s; i < e; i++) bt(S, cnt + 1, sum + v[i], i + 1, e, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; long long S; cin >> N >> S;
	v.assign(N, 0);
	for (auto& i : v) cin >> i;

	int mid = N >> 1;
	for (int i = 0; i < mid; i++) {
		bt(i + 1, 0, 0, 0, mid, 0);
	}

	for (int i = 0; i < N; i++) {
		bt(i + 1, 0, 0, mid, N, 1);
	}

	long long cnt = 0;
	for (auto& i : m[0]) {
		long long value = S - i.first;
		auto itr = m[1].find(value);
		if (itr != m[1].end()) cnt += itr->second * i.second;
	}
	auto itr = m[0].find(S);
	if (itr != m[0].end()) cnt += itr->second;
	itr = m[1].find(S);
	if (itr != m[1].end()) cnt += itr->second;

	cout << cnt;

}