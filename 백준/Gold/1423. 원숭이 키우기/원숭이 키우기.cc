#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, D;
	cin >> N;

	vector<int> monkey(N);
	for (auto& i : monkey) {
		cin >> i;
	}
	vector<long long> str(N);
	for (auto& i : str) {
		cin >> i;
	}

	cin >> D;

	vector<long long> dp(D + 1);

	// 시작할 때 힘 값
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += monkey[i] * str[i];
	}

	for (int i = 0; i < N - 1; i++) {

		monkey[i] = min(D, monkey[i]);

		// i레벨 원숭이를
		while (monkey[i]) {

			// d번째 일에 육성한다.
			for (int d = D - 1; d >= 0; d--) {
				
				// i레벨의 원숭이를 j레벨로 육성한다.
				for (int j = i + 1; j < N; j++) {
					int days = j - i;

					// 육성기간이 남은 날보다 길면 안된다.
					if (days + d > D) continue;
					
					dp[d + days] = max(dp[d + days], dp[d] + (str[j] - str[i]));
				}
			}
			monkey[i]--;
		}
	}
	cout << sum + dp[D];
}