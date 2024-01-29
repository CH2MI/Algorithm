#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	vector<int> arr1, arr2, arr3, dp;
	arr1.push_back(0); arr2.push_back(0); arr3.push_back(0); dp.push_back(0);
	arr1.push_back(1); arr2.push_back(0); arr3.push_back(0); dp.push_back(1);
	arr1.push_back(1); arr2.push_back(1); arr3.push_back(0); dp.push_back(2);
	arr1.push_back(2); arr2.push_back(1); arr3.push_back(1); dp.push_back(4);

	int i = 4;
	for (int t = 0; t < T; ++t) {
		int a;
		cin >> a;

		// 구하려는 값이 계산되지 않았을 때 dp를 구해준다.
		if (a >= i) {
			for (; i <= a; ++i) {

				// 1을 선택한 경우의 수는 dp[i - 1]의 경우의 수와 같다.
				arr1.push_back(dp[i - 1]);
				
				// 2를 선택한 경우의 수는 dp[i - 2]의 경우의 수와 같다.
				arr2.push_back(dp[i - 2]);

				// 3을 선택한 경우의 수는 dp[i - 3]의 경우의 수와 같다.
				arr3.push_back(dp[i - 3]);

				// i를 나타낼수 있는 방법은 1 2 3을 모두 합친 값이다.
				dp.push_back(arr1[i] + arr2[i] + arr3[i]);
			}
		}

		cout << dp[a] << '\n';
	}
}