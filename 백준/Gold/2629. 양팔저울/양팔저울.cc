#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> weight;
vector<vector<int>> dp;
int N;

void Cal(int i, int value) {
	if (dp[i][value]) return;

	dp[i][value] = 1;

	if (i == N) return;

	// 구슬은 왼쪽 저울에 있다고 가정

	// i번째 추를 올리지 않을 때
	Cal(i + 1, value);

	// i번째 추를 왼쪽에 올릴 때
	Cal(i + 1, value + weight[i]);

	// i번째 추를 오른쪽에 올릴 때
	Cal(i + 1, abs(value - weight[i]));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N;

	// 만들 수 있는 가장 큰 무게 = 추의 최대 무게(500) * 개수 (N)
	int mn = 500 * N + 1;
	weight.assign(N, 0);

	dp.assign(N + 1, vector<int>(mn, 0));

	for (auto& i : weight) {
		cin >> i;
	}

	Cal(0, 0);

	int M;
	cin >> M;

	while (M--) {
		int t; cin >> t;
		if (t >= mn) cout << "N ";
		else {
			int i;
			for (i = 1; i <= N; i++) { 
				if (dp[i][t]) {
					cout << "Y ";
					break;
				}
			}
			if (i > N) cout << "N ";
		}
	}
}