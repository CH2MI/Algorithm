#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		
		// 1을 더했을 때 제곱수의 개수
		dp[i] = dp[i - 1] + 1;

		// 'j의 제곱수 + 해당 값을 뺀 값의 dp값'을 찾아보면서 최소 갯수를 찾는다.
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N];
}