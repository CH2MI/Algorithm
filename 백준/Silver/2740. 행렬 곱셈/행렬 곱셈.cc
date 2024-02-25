#include <iostream>
#include <vector>
using namespace std;

// 행렬의 한 원소의 값을 구한다.
int solve(vector<vector<int>>& A, vector<vector<int>>& B, int i, int j, int M) {
	int sum = 0;
	for (int k = 0; k < M; k++) {
		sum += A[i][k] * B[k][j];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, K;

	// 행렬 A 입력
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	
	// 행렬 B 입력
	cin >> M >> K;
	vector<vector<int>> B(M, vector<int>(K));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}

	// 행렬 곱 
	vector<vector<int>> C(N, vector<int>(K));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			C[i][j] = solve(A, B, i, j, M);
		}
	}

	// 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << C[i][j] << ' ';
		}
		cout << '\n';
	}
}


