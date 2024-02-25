#include <iostream>
#include <vector>
using namespace std;

int N;

// 행렬의 한 원소의 값을 구한다.
int solve(vector<vector<int>>& A, vector<vector<int>>& B, int i, int j) {
	int sum = 0;
	for (int k = 0; k < N; k++) {
		sum += A[i][k] * B[k][j] % 1000;
	}
	return sum % 1000;
}

vector<vector<int>> recursion(vector<vector<int>>& A, long long B) {
	vector<vector<int>> ret(N, vector<int>(N));
	vector<vector<int>> C;

	if (B == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret[i][j] = A[i][j] % 1000;
			}
		}
		return ret;
	}
	else if (B == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret[i][j] = solve(A, A, i, j);
			}
		}
		return ret;
	}
	else if (B == 3) {
		C = recursion(A, B - 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret[i][j] = solve(C, A, i, j);
			}
		}
		return ret;
	}

	C = recursion(A, B / 2);
	if (B % 2 == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret[i][j] = solve(C, C, i, j);
			}
		}
		return ret;
	}
	else {
		vector<vector<int>> D(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				D[i][j] = solve(C, C, i, j);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret[i][j] = solve(D, A, i, j);
			}
		}
		return ret;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	
	long long B;
	cin >> N >> B;

	vector<vector<int>> A(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	for (auto i : recursion(A, B)) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}