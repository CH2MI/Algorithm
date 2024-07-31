#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, K, D;
vector<tuple<int, int, int>> Policys;

bool solve(int mid) {
	long long d = 0;

	for (const auto& [a, b, c] : Policys) {

		// 규칙의 구간이 전부 포함될 때
		if (b < mid) {
			int len = b - a;
			d += len / c + 1;
		}

		// 규칙의 구간안에 존재할 때
		else if (a <= mid) {
			int len = mid - a;
			d += len / c + 1;
		}
	}
	return d >= D;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K >> D;
	Policys.assign(K, tuple<int, int, int>());

	for (auto& i : Policys) {
		int a, b, c;
		cin >> a >> b >> c;
		i = { a, b, c };
	}

	int lo = 0;
	int hi = N;

	while (lo + 1 < hi) {
		int mid = lo + (hi - lo) / 2;
		if (solve(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}