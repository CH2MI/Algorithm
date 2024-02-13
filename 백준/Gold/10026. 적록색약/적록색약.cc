#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> arr;
vector<vector<bool>> visited;
int N;

bool f(int x, int y, int mode, char flag) {
	if (!mode) {
		return arr[x][y] != flag;
	}

	if (flag == 'B') {
		return arr[x][y] != 'B';
	}
	return arr[x][y] == 'B';
}

void commonbfs(int x, int y, int mode) {
	char flag = arr[x][y];
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		if (i < 0 || i >= N || j < 0 || j >= N) continue;
		if (visited[i][j]) continue;
		if (f(i, j, mode, flag)) continue;

		
		visited[i][j] = true;

		q.push({ i + 1, j });
		q.push({ i - 1, j });
		q.push({ i, j + 1 });
		q.push({ i, j - 1 });
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	cin.ignore();

	arr.assign(N, string());
	visited.assign(N, vector<bool>(N));
	for (int i = 0; i < N; i++) 
		getline(cin, arr[i]);
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				commonbfs(i, j, 0);
			}
		}
	}
	cout << cnt << ' ';

	visited.assign(N, vector<bool>(N));
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				commonbfs(i, j, 1);
			}
		}
	}
	cout << cnt;
}