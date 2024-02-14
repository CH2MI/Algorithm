#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

bool cmp(const tuple<int, int, int>& A, const tuple<int, int, int>& B) {
	int a1 = get<0>(A), a2 = get<1>(A);
	int b1 = get<0>(B), b2 = get<1>(B);
	
	if (a2 == b2) return a1 < b1;
	return a2 < b2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	vector<tuple<int, int, int>> v(N);
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;

		// 시작일, 종료일, 금액을 튜플로 묶어 저장한다.
		v[i] = make_tuple(i + 1, i + T, P);
	}

	// 종료일을 기준으로 오름차순 정렬을 한다.
	sort(v.begin(), v.end(), cmp);

	vector<int> dp(N + 1);
	
	int j = 0;
	dp[0] = 0;

	// i : v의 인덱스
	for (int i = 0; i < N; i++) {
		
		// 현재 인덱스의 종료일을 가져온다.
		int sel = get<1>(v[i]);

		// 종료일이 마지막날을 초과하면 전날 것을 가져온다.
		// 이후는 돌릴 필요가 없다.
		if (sel > N) {
			cout << dp[j];
			return 0;
		}

		// 해당 종료일까지 번 돈이 없으므로 종료일까지는 그전의 dp 값과 같다.
		while (j < sel) {
			++j;
			dp[j] = dp[j - 1];
		}

		// 위 과정을 거치면 dp의 인덱스가 종료일과 동일하다.

		// 시작일의 전날을 가져온다.
		int k = get<0>(v[i]) - 1;

		// j번째날의 최대 수익은 해당 종료일을 선택했을 때와 선택하지 않았을 때에서 고른다.
		dp[j] = max(dp[k] + get<2>(v[i]), dp[j]);
	}
	cout << dp[N];
}