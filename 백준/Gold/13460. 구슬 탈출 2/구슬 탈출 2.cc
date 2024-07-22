#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10


vector<string> board;
int N, M;
pair<int, int> Blue, Red;

int recursion(int cnt, pair<int, int> R, pair<int, int> B);

void Input() {
	cin >> N >> M;
	board = vector<string>(N);

	for (int i = 0; i < N; i++) {
		cin >> board[i];
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'B') {
				Blue = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'R') {
				Red = { i, j };
				board[i][j] = '.';
			}
		}
	}
}

// 벽에 닿을 때까지 움직인다.
bool move(pair<int, int>& ball, pair<int, int>& obj, int dx, int dy) {
	int ballx = ball.first;
	int bally = ball.second;
	int objx = obj.first;
	int objy = obj.second;
	bool f = false;

	while (true) {
		int i = ballx + dx;
		int j = bally + dy;

		if (board[i][j] == '#')
			break;
		if (board[i][j] != 'O' && i == objx && j == objy)
			break;

		ballx = i;
		bally = j;
		if (board[i][j] == 'O') {
			f = true;
			break;
		}
	}
	ball.first = ballx;
	ball.second = bally;
	return f;
}

int Up(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.first <= B.first) {
		if (move(R, B, -1, 0)) {
			if (!move(B, R, -1, 0))
				return cnt;
			else
				return MAX;
		}
		if (move(B, R, -1, 0))
			return MAX;
		else
			return recursion(cnt + 1, R, B);
	}
	else {
		if (move(B, R, -1, 0))
			return MAX;
		else {
			if (move(R, B, -1, 0))
				return cnt;
			else
				return recursion(cnt + 1, R, B);
		}
	}
}

int Down(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.first >= B.first) {
		if (move(R, B, 1, 0)) {
			if (!move(B, R, 1, 0))
				return cnt;
			else
				return MAX;
		}
		if (move(B, R, 1, 0))
			return MAX;
		else
			return recursion(cnt + 1, R, B);
	}
	else {
		if (move(B, R, 1, 0))
			return MAX;
		else {
			if (move(R, B, 1, 0))
				return cnt;
			else
				return recursion(cnt + 1, R, B);
		}
	}
}

int Left(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.second <= B.second) {
		if (move(R, B, 0, -1)) {
			if (!move(B, R, 0, -1))
				return cnt;
			else
				return MAX;
		}
		if (move(B, R, 0, -1))
			return MAX;
		else
			return recursion(cnt + 1, R, B);
	}
	else {
		if (move(B, R, 0, -1))
			return MAX;
		else {
			if (move(R, B, 0, -1))
				return cnt;
			else
				return recursion(cnt + 1, R, B);
		}
	}
}

int Right(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.second >= B.second) {
		if (move(R, B, 0, 1)) {
			if (!move(B, R, 0, 1))
				return cnt;
			else
				return MAX;
		}
		if (move(B, R, 0, 1))
			return MAX;
		else
			return recursion(cnt + 1, R, B);
	}
	else {
		if (move(B, R, 0, 1))
			return MAX;
		else {
			if (move(R, B, 0, 1))
				return cnt;
			else
				return recursion(cnt + 1, R, B);
		}
	}
}

int recursion(int cnt, pair<int, int> R, pair<int, int> B) {
	if (cnt == MAX) return MAX;

	int mn = MAX;
	mn = min({ Up(cnt, R, B), Down(cnt, R, B), Left(cnt, R, B), Right(cnt, R, B) });

	return mn;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Input();
	int answer = recursion(0, Red, Blue);
	if (answer == MAX) cout << "-1";
	else cout << answer + 1;
}