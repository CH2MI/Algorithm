#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	// 연속 합을 구한다.
	vector<int> sum;
	sum.push_back(0);
	for (int i = 0; i < N; i++) {
		sum.push_back(sum[i] + v[i]);
	}
	// 연속 적인 K일 온도에서 최대 값을 구한다.
	int max = -100000000;
	for (int i = 1; i <= N - K + 1; i++) {
		int t = sum[i + K - 1] - sum[i - 1];
		if (max < t) max = t;
	}
	cout << max << '\n';
}
