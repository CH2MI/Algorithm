#include <iostream>
#include <vector>
using namespace std;

int c = 0;

bool Find(bool** selected, int x, int y, int N) {
	for (int i = 1; i < N; i++) {
		int x1 = x - i;
		int x2 = x + i;
		int y1 = y - i;
		int y2 = y + i;
		if (0 <= x1) {
			if (selected[x1][y]) return false;
			if (0 <= y1) if (selected[x1][y1]) return false;
			if (y2 < N) if (selected[x1][y2]) return false;
		}
		if (x2 < N) {
			if (selected[x2][y]) return false;
			if (0 <= y1) if (selected[x2][y1]) return false;
			if (y2 < N) if (selected[x2][y2]) return false;
		}
		if (0 <= y1) if(selected[x][y1]) return false;
		if (y2 < N) if(selected[x][y2]) return false;
	}
	return true;
}

void dfs(bool** selected, vector<int> l, int x, int count, int N) {
	if (count == N) {
		c++;
		return;
	}

	for (int i = 0; i < l.size(); i++) {
		selected[x][l[i]] = true;
		vector<int> t = l;
		t.erase(t.begin() + i);
		if (Find(selected, x, l[i], N))
			dfs(selected, t, x + 1, count + 1, N);
		selected[x][l[i]] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<int> l;
	int N;
	cin >> N;
	bool** selected = new bool* [N];
	for (int i = 0; i < N; i++) {
		selected[i] = new bool[N];
		l.push_back(i);
		for (int j = 0; j < N; j++)
			selected[i][j] = false;
	}
	dfs(selected, l, 0, 0, N);
	cout << c;
}