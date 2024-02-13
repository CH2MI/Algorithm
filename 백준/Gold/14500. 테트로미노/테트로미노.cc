#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	int Max = 0;

	// ----
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {
			int t = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3];
			Max = max(Max, t);
		}
	}

	// -
	// -
	// -
	// -
	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < M; j++) {
			int t = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j];
			Max = max(Max, t);
		}
	}

	// --
	// --
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int t = v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1];
			Max = max(Max, t);
		}
	}

	//  - -  -- -- -   - -   -
	//  - -  -   - -- -- -- --
	// -- -- -   - -   -  - -
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			int t = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j + 1];
			Max = max(Max, t);

			t = v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j] + v[i + 2][j + 1];
			Max = max(Max, t);

			t = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i][j + 1];
			Max = max(Max, t);

			t = v[i][j + 1] + v[i + 1][j + 1] + v[i][j] + v[i + 2][j + 1];
			Max = max(Max, t);

			t = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1];
			Max = max(Max, t);

			t = v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j] + v[i + 2][j + 1];
			Max = max(Max, t);

			t = v[i][j] + v[i + 1][j] + v[i + 2][j + 1] + v[i + 1][j + 1];
			Max = max(Max, t);

			t = v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j] + v[i + 2][j];
			Max = max(Max, t);
		}
	}

	// --- --- -     - ---  -   -- --
	//   - -   --- ---  -  --- --   --
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int t = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2];
			Max = max(Max, t);

			t = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j];
			Max = max(Max, t);

			t = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
			Max = max(Max, t);

			t = v[i][j + 2] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
			Max = max(Max, t);

			t = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1];
			Max = max(Max, t);

			t = v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
			Max = max(Max, t);

			t = v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1] + v[i][j + 2];
			Max = max(Max, t);

			t = v[i][j + 1] + v[i][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
			Max = max(Max, t);
		}
	}

	cout << Max;
}