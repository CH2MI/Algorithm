#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N + 1]();
	int* dp = new int[N + 1]();
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[0] = 1001;

	int m = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j])
				if (dp[j] > cnt) cnt = dp[j];
		}
		dp[i] = cnt + 1;
		m = max(dp[i], m);
	}
	cout << m;
}