#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {

		int N, ci, cy, hi, hy;
		cin >> N;
		vector<vector<int>> v(N, vector<int>(2));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[j][i];
			}
		}
		cin >> ci >> cy >> hi >> hy;
		--cy; --hy;
		vector<int> dp(N + 2);

		// 계산의 편의를 위해 코코의 위치를 상대적으로 더 왼쪽에 놓는다.
		if (hi < ci) {
			int t = hi;
			hi = ci;
			ci = t;

			t = hy;
			hy = cy;
			cy = t;
		} 

		// 코코의 집 보다 x 좌표가 작은 쪽을 들린다.
		for (int i = 1; i < ci; i++) {

			// 왼쪽 지역을 더 탐색하거나 가지 않는 경우
			int prev = max({ dp[i - 1], 0 });

			// y좌표가 0인 곳만, 1인 곳만, 둘 다 탐색하는 경우와 더 왼쪽들을 탐색하는 경우
			dp[i] = max({ v[i - 1][0], v[i - 1][1], v[i - 1][0] + v[i - 1][1] + prev });
		}

		// 한별이의 집보다 x 좌표가 큰 쪽을 들린다.
		for (int i = N; i > hi; i--) {

			// 오른쪽 지역을 더 탐색하거나 가지 않는 경우
			int next = max({ dp[i + 1], 0 });

			// y좌표가 0인 곳만, 1인 곳만, 둘 다 탐색하는 경우와 더 왼쪽들을 탐색하는 경우
			dp[i] = max({ v[i - 1][0], v[i - 1][1], v[i - 1][0] + v[i - 1][1] + next });
		}

		int i = ci;

		// 코코와 한별이가 같은 x이면 왼쪽과 오른쪽, 0 중에서 하나를 고른다.
		if (ci == hi) {
			dp[i] = max({ dp[i - 1], dp[i + 1], 0 }) + v[i - 1][0] + v[i - 1][1];
		}

		// 다르면 코코와 한별이 사이의 x 좌표들도 탐색 해야한다.  
		else {
			
			// 코코의 집에서 출발할 때 왼쪽을 들릴지 결정한다.
			dp[i] = max({ 0, v[i - 1][!cy], v[i - 1][!cy] + dp[i - 1]}) + v[i - 1][cy];
			++i;

			// 사이의 집도 확인한다.
			for (; i < hi; i++) {
				dp[i] = max({ v[i - 1][0], v[i - 1][1], v[i - 1][0] + v[i - 1][1] }) + dp[i - 1];
			}

			// 한별이의 집에 가기 전에 오른쪽을 들릴지 결정한다.
			dp[i] = max({ 0, v[i - 1][!hy], v[i - 1][!hy] + dp[i + 1] }) + v[i - 1][hy] + dp[i - 1];
		}
		cout << dp[i] << '\n';
	}
}