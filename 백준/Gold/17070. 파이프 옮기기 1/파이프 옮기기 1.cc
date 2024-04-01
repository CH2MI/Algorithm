#include <iostream>
#include <vector>
using namespace std;

int N;
int v[16][16];
int dp[16][16][3];

// 가로 상태일 때 할 수 있는 행동들
void action1(int i, int j) {

	// 1. 가로로 밀기
	if (j < N - 2) {
		if (!v[i][j + 2]) {
			dp[i][j + 1][0] += dp[i][j][0];
		}
	}

	// 2. 대각선으로 밀기
	if (i < N - 1 && j < N - 2) {
		if (!v[i][j + 2] && !v[i + 1][j + 1] && !v[i + 1][j + 2]) {
			dp[i][j + 1][1] += dp[i][j][0];
		}
	}
}

// 대각선 상태일 때 할 수 있는 행동들
void action2(int i, int j) {

	// 1. 가로로 밀기
	if (i < N - 1 && j < N - 2) {
		if (!v[i + 1][j + 2]) {
			dp[i + 1][j + 1][0] += dp[i][j][1];
		}
	}

	// 2. 대각선으로 밀기
	if (i < N - 2 && j < N - 2) {
		if (!v[i + 1][j + 2] && !v[i + 2][j + 1] && !v[i + 2][j + 2]) {
			dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}

	// 3. 세로로 밀기
	if (i < N - 2 && j < N - 1) {
		if (!v[i + 2][j + 1]) {
			dp[i + 1][j + 1][2] += dp[i][j][1];
		}
	}
}

// 세로 상태일 때 할 수 있는 행동들
void action3(int i, int j) {

	// 1. 대각선으로 밀기
	if (i < N - 2 && j < N - 1) {
		if (!v[i + 1][j + 1] && !v[i + 2][j] && !v[i + 2][j + 1]) {
			dp[i + 1][j][1] += dp[i][j][2];
		}
	}
	
	// 2. 세로로 밀기
	if (i < N - 2) {
		if (!v[i + 2][j]) {
			dp[i + 1][j][2] += dp[i][j][2];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	dp[0][0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			// 각 위치에 파이프가 있다면 행동을 실행한다.
			if (dp[i][j][0]) action1(i, j);
			if (dp[i][j][1]) action2(i, j);
			if (dp[i][j][2]) action3(i, j);
		}
	}

	// 세로, 대각선, 가로로 왔을 때 경우의 수를 더해준다.
	cout << dp[N - 2][N - 1][2] + dp[N - 2][N - 2][1] + dp[N - 1][N - 2][0];
}
