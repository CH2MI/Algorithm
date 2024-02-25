#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

vector<vector<long long>> A = { {1, 1}, {1, 0} };
int N = 2;

inline long long solve(vector<vector<long long>>& A, vector<vector<long long>> & B, int i, int j) {
	return ((A[i][0] * B[0][j] % MOD) + (A[i][1] * B[1][j] % MOD)) % MOD;
}

vector<vector<long long>> recursion(long long n) {
	vector<vector<long long>> ret(2, vector<long long>(2));
	vector<vector<long long>> C(2, vector<long long>(2)), D(2, vector<long long>(2));
	if (n == 1) return A;
	else if (n == 2) {
		ret[0][0] = solve(A, A, 0, 0);
		ret[0][1] = solve(A, A, 0, 1);
		ret[1][0] = solve(A, A, 1, 0);
		ret[1][1] = solve(A, A, 1, 1);
		return ret;
	}
	else if (n == 3) {
		C = recursion(n - 1);
		ret[0][0] = solve(C, A, 0, 0);
		ret[0][1] = solve(C, A, 0, 1);
		ret[1][0] = solve(C, A, 1, 0);
		ret[1][1] = solve(C, A, 1, 1);
		return ret;
	}

	C = recursion(n / 2);
	D[0][0] = solve(C, C, 0, 0);
	D[0][1] = solve(C, C, 0, 1);
	D[1][0] = solve(C, C, 1, 0);
	D[1][1] = solve(C, C, 1, 1);

	if (n % 2 == 0) return D;

	ret[0][0] = solve(D, A, 0, 0);
	ret[0][1] = solve(D, A, 0, 1);
	ret[1][0] = solve(D, A, 1, 0);
	ret[1][1] = solve(D, A, 1, 1);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long n;
	cin >> n;

	vector<vector<long long>> ret = recursion(n);
	cout << ret[0][1];
}