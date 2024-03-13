#include <iostream>
#include <numeric>
#define MOD 1000000007
using namespace std;

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
	long long sum = 0;

	for (int i = 0; i < M; i++) {
		long long N, S;
		cin >> N >> S;

		// 기약 분수로 만든다.
		long long t = gcd(N, S);
		N /= t;
		S /= t;

		sum = (sum + (S * solve(N, MOD - 2, MOD)) % MOD) % MOD;
	}
	cout << sum;
}