#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int c[3] = { 0 };

void recursion(int size, int I, int J) {

	int cnt[3] = { 0 };

	for (int i = I; i < I + size; i++) {
		for (int j = J; j < J + size; j++) {
			if (v[i][j] == -1) cnt[0]++;
			else if (!v[i][j]) cnt[1]++;
			else cnt[2]++;
		}
	}

	int S = size * size;
	if (cnt[0] == S) ++c[0];
	else if (cnt[1] == S) ++c[1];
	else if (cnt[2] == S) ++c[2];
	else {
		size /= 3;

		recursion(size, I, J);
		recursion(size, I + size, J);
		recursion(size, I + 2 * size, J);
		recursion(size, I, J + size);
		recursion(size, I + size, J + size);
		recursion(size, I + 2 * size, J + size);
		recursion(size, I, J + 2 * size);
		recursion(size, I + size, J + 2 * size);
		recursion(size, I + 2 * size, J + 2 * size);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	v.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	recursion(N, 0, 0);
	cout << c[0] << '\n' << c[1] << '\n' << c[2];
}