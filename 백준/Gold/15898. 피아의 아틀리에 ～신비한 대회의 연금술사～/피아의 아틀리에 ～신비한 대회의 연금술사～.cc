#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<vector<vector<int>>, vector<vector<char>>> pic;

vector<pic> v;
int N;

void Input()
{
	cin >> N;
	v.assign(N, { vector<vector<int>>(4, vector<int>(4, 0)), vector<vector<char>>(4, vector<char>(4, 0)) });

	for (auto& i : v) {
		for (auto& j : i.first) {
			for (auto& k : j) cin >> k;
		}
		for (auto& j : i.second) {
			for (auto& k : j) cin >> k;
		}
	}
}

// 재료를 돌렸을 때 i좌표
inline int GetI(int x, int y, int n, int wx, int wy) {
	if (n == 0) return x - wx;
	else if (n == 1) return y - wy;
	else if (n == 2) return 3 - x + wx;
	else return 3 - y + wy;
}

// 재료를 돌렸을 때 j좌표
inline int GetJ(int x, int y, int n, int wx, int wy) {
	if (n == 0) return y - wy;
	else if (n == 1) return 3 - x + wx;
	else if (n == 2) return 3 - y + wy;
	else return x - wx;
}

inline void UpdateValue(int& a, int& b) {
	if (a + b < 0) a = 0;
	else if (a + b >= 9) a = 9;
	else a += b;
}

void GetLocate(pic&g, pic& pi, int m, int n) {
	if (m == 0) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				int i = GetI(x, y, n, 0, 0);
				int j = GetJ(x, y, n, 0, 0);
				
				UpdateValue(g.first[x][y], pi.first[i][j]);

				if (pi.second[i][j] != 'W')
					g.second[x][y] = pi.second[i][j];
			}
		}
	}
	else if (m == 1) {
		for (int x = 1; x < 5; x++) {
			for (int y = 0; y < 4; y++) {
				int i = GetI(x, y, n, 1, 0);
				int j = GetJ(x, y, n, 1, 0);

				UpdateValue(g.first[x][y], pi.first[i][j]);

				if (pi.second[i][j] != 'W')
					g.second[x][y] = pi.second[i][j];
			}
		}
	}
	else if (m == 2) {
		for (int x = 0; x < 4; x++) {
			for (int y = 1; y < 5; y++) {
				int i = GetI(x, y, n, 0, 1);
				int j = GetJ(x, y, n, 0, 1);

				UpdateValue(g.first[x][y], pi.first[i][j]);

				if (pi.second[i][j] != 'W')
					g.second[x][y] = pi.second[i][j];
			}
		}
	}
	else {
		for (int x = 1; x < 5; x++) {
			for (int y = 1; y < 5; y++) {
				int i = GetI(x, y, n, 1, 1);
				int j = GetJ(x, y, n, 1, 1);

				UpdateValue(g.first[x][y], pi.first[i][j]);

				if (pi.second[i][j] != 'W')
					g.second[x][y] = pi.second[i][j];
			}
		}
	}
}

int CalMaxValue(pic& p) {
	int R = 0, B = 0, G = 0, Y = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			switch (p.second[i][j])
			{
			case 'R':
				R += p.first[i][j];
				break;
			case 'B':
				B += p.first[i][j];
				break;
			case 'G':
				G += p.first[i][j];
				break;
			case 'Y':
				Y += p.first[i][j];
				break;
			}
		}
	}

	return 7 * R + 5 * B + 3 * G + 2 * Y;
}

int Cal(pic& I, pic& J, pic& K) {
	int mx = 0;
	

	// 전체 경우의 수 중에서 p를 돌리면 똑같은 경우의 수가 나오므로 첫번째 재료는 왼쪽상단에 고정
	for (int i = 0; i < 4; i++) {	
		for (int j = 0; j < 16; j++) {		
			for (int k = 0; k < 16; k++) {
				pic g = { vector<vector<int>>(5, vector<int>(5, 0)), vector<vector<char>>(5, vector<char>(5, 'W')) };
				
				// i, j, k 순서대로 배치한다.
				GetLocate(g, I, i / 4, i % 4);
				GetLocate(g, J, j / 4, j % 4);
				GetLocate(g, K, k / 4, k % 4);

				mx = max(mx, CalMaxValue(g));
			}
		}
	}
	return mx;
}

int Solve() {
	int mx = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			for (int k = 0; k < N; k++) {
				if (i == k || j == k) continue;

				// 서로 다른 3개를 고른다.
				mx = max(mx, Cal(v[i], v[j], v[k]));
			}
		}
	}
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Input();
	cout << Solve();
}