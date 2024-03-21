#include <iostream>
#define MOD 10007
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	if (N < 4) {
		cout << N;
		return 0;
	}

	long long r = N / 3;
	int q = N % 3;

	long long ret;

	// 나머지가 1일 땐 3 * 1 < 2 * 2
	if (q == 1) {
		ret = 4;
		--r;
	}

	// 나머지가 2일 땐 3 * 2
	else if (q == 2) {
		ret = 6;
		--r;
	}

	// 나머지가 0이면 3
	else
		ret = 1;

	for (int i = 0; i < r; i++)
		ret = ret * 3 % MOD;

	cout << ret;
}