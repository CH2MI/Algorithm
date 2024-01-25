#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<long long> v(N), sum(N + 1), m(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sum[0] = 0;
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + v[i];
		m[i] = sum[i + 1] % M;
	}
	// 0의 개수
	long long s = count(m.begin(), m.end(), 0);
	// 같은 나머지를 같는 구간들의 조합의 합
	for (int i = 0; i < M; i++) {
		long long t = count(m.begin(), m.end(), i);
		s += t * (t - 1) / 2;

	}
	cout << s << '\n';
}