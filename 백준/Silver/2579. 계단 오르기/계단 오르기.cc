#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<int> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	int* dp = new int[N];
	int* continuous = new int[N]; int* discontinuous = new int[N];
	dp[0] = continuous[0] = discontinuous[0] = v[0];
	if (N > 1) {
		dp[1] = continuous[1] = dp[0] + v[1];
		discontinuous[1] = v[1];
	}

	for (int i = 2; i < N; i++) {
		continuous[i] = discontinuous[i - 1] + v[i];
		discontinuous[i] = dp[i - 2] + v[i];
		dp[i] = max(continuous[i], discontinuous[i]);
	}
	cout << dp[N - 1];

} 