#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10


vector<string> board;
int N, M;
pair<int, int> Blue, Red;

string recursion(int cnt, pair<int, int> R, pair<int, int> B);

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

string Up(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.first <= B.first) {
		if (move(R, B, -1, 0)) {
			if (!move(B, R, -1, 0))
				return "U";
			else
				return "X";
		}
		if (move(B, R, -1, 0))
			return "X";
		else {
			string s = recursion(cnt + 1, R, B);
			if (s != "X") s = "U" + s;
			return s;
		}
	}
	else {
		if (move(B, R, -1, 0))
			return "X";
		else {
			if (move(R, B, -1, 0))
				return "U";
			else {
				string s = recursion(cnt + 1, R, B);
				if (s != "X") s = "U" + s;
				return s;
			}
		}
	}
}

string Down(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.first >= B.first) {
		if (move(R, B, 1, 0)) {
			if (!move(B, R, 1, 0))
				return "D";
			else
				return "X";
		}
		if (move(B, R, 1, 0))
			return "X";
		else {
			string s = recursion(cnt + 1, R, B);
			if (s != "X") s = "D" + s;
			return s;
		}
	}
	else {
		if (move(B, R, 1, 0))
			return "X";
		else {
			if (move(R, B, 1, 0))
				return "D";
			else {
				string s = recursion(cnt + 1, R, B);
				if (s != "X") s = "D" + s;
				return s;
			}
		}
	}
}

string Left(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.second <= B.second) {
		if (move(R, B, 0, -1)) {
			if (!move(B, R, 0, -1))
				return "L";
			else
				return "X";
		}
		if (move(B, R, 0, -1))
			return "X";
		else {
			string s = recursion(cnt + 1, R, B);
			if (s != "X") s = "L" + s;
			return s;
		}
	}
	else {
		if (move(B, R, 0, -1))
			return "X";
		else {
			if (move(R, B, 0, -1))
				return "L";
			else {
				string s = recursion(cnt + 1, R, B);
				if (s != "X") s = "L" + s;
				return s;
			}
		}
	}
}

string Right(int cnt, pair<int, int> R, pair<int, int> B) {
	if (R.second >= B.second) {
		if (move(R, B, 0, 1)) {
			if (!move(B, R, 0, 1))
				return "R";
			else
				return "X";
		}
		if (move(B, R, 0, 1))
			return "X";
		else {
			string s = recursion(cnt + 1, R, B);
			if (s != "X") s = "R" + s;
			return s;
		}
	}
	else {
		if (move(B, R, 0, 1))
			return "X";
		else {
			if (move(R, B, 0, 1))
				return "R";
			else {
				string s = recursion(cnt + 1, R, B);
				if (s != "X") s = "R" + s;
				return s;
			}
		}
	}
}

string recursion(int cnt, pair<int, int> R, pair<int, int> B) {
	if (cnt == MAX) return "X";

	int mn = MAX + 1;
	string route("X");
	string t = Up(cnt, R, B);
	if (t != "X" && t.size() < mn) {
		route = t;
		mn = t.size();
	}

	t = Down(cnt, R, B);
	if (t != "X" && t.size() < mn) {
		route = t;
		mn = t.size();
	}

	t = Left(cnt, R, B);
	if (t != "X" && t.size() < mn) {
		route = t;
		mn = t.size();
	}

	t = Right(cnt, R, B);
	if (t != "X" && t.size() < mn) {
		route = t;
		mn = t.size();
	}

	return route;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Input();
	string answer = recursion(0, Red, Blue);
	if (answer == "X") 
		cout << "-1";
	else 
		cout << answer.size() << '\n' << answer;
}