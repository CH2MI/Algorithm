#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K; cin >> N >> K;
	
	vector<int> v(N);
	vector<int> cnt(100001);

	for (int& i : v) cin >> i;

	int l = 0, r = 0;

	int cur = v[r];
	int mx = 0;
	while (r < N) {
		cnt[v[r]]++;

		if (cnt[v[r]] > K) {
			while (v[l] != v[r]) {
				cnt[v[l++]]--;
			}
			cnt[v[l++]]--;
		}
		r++;
		mx = max(mx, r - l);
	}
	cout << mx;
}