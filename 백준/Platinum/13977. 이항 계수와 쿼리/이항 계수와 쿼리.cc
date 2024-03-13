#include <iostream>
#define MOD 1000000007
#define MAX 4000001
using namespace std;

int F[MAX];

void fac() {
	long long sum = 1;
	for (long long i = 1; i < MAX; i++) {
		sum = (sum * i) % MOD;
		F[i] = sum;
	}
}

long long solve(int A, int B, int C) {
	if (B == 1) return A % C;

	long long ret = solve(A, B / 2, C);

	if (B % 2 == 0)
		return (ret * ret) % C;
	else
		return (ret * ret % C) * A % C;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int M;
	cin >> M;
	
	fac();

	for (int i = 0; i < M; i++) {
		long long N, K;
		cin >> N >> K;

		long long a = F[N], b = F[K], c = F[N - K];

		if (K == 0) b = 1;
		if (N - K == 0) c = 1;

		long long d = (b * c) % MOD;
		cout << a * solve(d, MOD - 2, MOD) % MOD << '\n';
	}
}