#include <iostream>

using namespace std;

long long a, b, c;
long long MOD = 1000000007;
long long N, K;

// N!, K!, (N - K)!을 구한다.
void fac() {
	long long s = 1;
	long long i = 0;
	while (++i <= N) {
		s = (s * i) % MOD;
		if (i == N) a = s;
		if (i == K) b = s;
		if (i == N - K) c = s;
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

	cin >> N >> K;
	fac();
	if (K == 0) b = 1;
	if (N - K == 0) c = 1;
	long long d = (b * c) % MOD;
	long long e = a * solve(d, MOD - 2, MOD) % MOD;
	cout << e;
}