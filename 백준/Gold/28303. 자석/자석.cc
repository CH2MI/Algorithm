#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long N, K;
	cin >> N >> K;

	vector<long long> v(N);

	for (auto& i : v) {
		cin >> i;
	}

	int s = 0, n = N - 1;
	long long s_mn = v[0], n_mn = v[N - 1];
	long long s_mxdiff = LLONG_MIN, n_mxdiff = LLONG_MIN;

	for (int i = 1; i < N; i++) {
		if (v[i] >= s_mn) {
			s_mxdiff = max(s_mxdiff, v[i] - s_mn - K);
		}
		s_mn = min(s_mn + K, v[i]);
		
		if (v[N - i - 1] >= n_mn) {
			n_mxdiff = max(n_mxdiff, v[N - i - 1] - n_mn - K);
		}
		n_mn = min(n_mn + K, v[N - i - 1]);
	}

	cout << max(s_mxdiff, n_mxdiff);

}