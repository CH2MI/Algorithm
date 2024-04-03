#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int Room[50][50][2];
int R, C;
int AR, AC;

void Diffusion() {

	// init
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) 
			Room[i][j][1] = 0;

	// simulation
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Room[i][j][0] < 1) continue;
			int cnt = 0;
			int value = Room[i][j][0] / 5;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x < 0 || x >= R || y < 0 || y >= C) continue;
				if (Room[x][y][0] == -1) continue;
				++cnt;
				Room[x][y][1] += value;
			}
			Room[i][j][1] += Room[i][j][0] - value * cnt;
		}
	}

	// apply
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) 
			if (Room[i][j][1] > 0) Room[i][j][0] = Room[i][j][1];
}

void wind() {

	// 위쪽 청정기
	int i = AR - 2;
	for (; i > 0; i--) {
		Room[i][0][0] = Room[i - 1][0][0];
	}
	int j = 0;
	for (; j < C - 1; j++) {
		Room[i][j][0] = Room[i][j + 1][0];
	}
	for (; i < AR - 1; i++) {
		Room[i][j][0] = Room[i + 1][j][0];
	}
	for (; j > 1; j--) {
		Room[i][j][0] = Room[i][j - 1][0];
	}
	Room[AR - 1][1][0] = 0;

	// 아래쪽 청정기
	i = AR + 1;
	for (; i < R - 1; i++) {
		Room[i][0][0] = Room[i + 1][0][0];
	}
	j = 0;
	for (; j < C - 1; j++) {
		Room[i][j][0] = Room[i][j + 1][0];
	}
	for (; i > AR; i--) {
		Room[i][j][0] = Room[i - 1][j][0];
	}
	for (; j > 1; j--) {
		Room[i][j][0] = Room[i][j - 1][0];
	}
	Room[AR][1][0] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> Room[i][j][0];
			if (Room[i][j][0] == -1) {
				AR = i;
				AC = j;
			}
		}
	}

	while (T--) {
		Diffusion();
		wind();
	}

	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Room[i][j][0] > 0) cnt += Room[i][j][0];
		}
	}
	cout << cnt;

}
