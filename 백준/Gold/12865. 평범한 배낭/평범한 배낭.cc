#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
	int w, v;
};

bool cmp(Data a, Data b) {
	return a.w < b.w;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<Data> v;
	for (int i = 0; i < N; i++) {
		Data d;
		cin >> d.w >> d.v;
		v.push_back(d);
	}

	sort(v.begin(), v.end(), cmp);

	int** dp = new int*[K + 1];
	for (int i = 0; i <= K; i++) {
		dp[i] = new int[N]();
		if (i < v[0].w) continue;
		for (int j = 0; j < N; j++) {
			int c = i - v[j].w;
			if (j == 0) dp[i][j] = v[0].v;
			else if (c < 0) dp[i][j] = dp[i][j - 1];
			else {
				dp[i][j] = max(v[j].v + dp[c][j - 1], dp[i][j - 1]);
			}
		}
	}

	cout << dp[K][N - 1];
		
}