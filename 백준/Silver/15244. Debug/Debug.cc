#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	map<int, int> m;
	for (int i = 0; i < K; i++) {
		int k; cin >> k;
		m[k]++;
	}

	vector<int> v(N);
	for (auto& [j, k] : m) {
		int i = 0;
		while (i < N) {
			v[i] += k;
			i += j;
		}
	}

	vector<long long> sum(N + 1);
	for (int i = 0; i < N; i++) sum[i + 1] = sum[i] + v[i];

	int Q; cin >> Q;

	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << sum[R + 1] - sum[L] << '\n';
	}
}