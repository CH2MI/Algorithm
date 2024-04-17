#include <iostream>
#include <vector>
#define INF 1e9 + 1
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int l, r, sum, len;
	l = r = 0;
	sum = v[0];
	len = INF;

	while (r < N) {
		if (sum < S) {
			if (++r < N) sum += v[r];
		}
		else {
			len = min(len, r - l + 1);
			sum -= v[l++];
		}
	}

	if (len == INF) cout << '0';
	else cout << len;
}