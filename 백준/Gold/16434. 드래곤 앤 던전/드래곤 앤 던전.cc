#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

int N;
long long ATK;
vector<tuple<int, long long, long long>> Rooms;

bool solve(long long mid) {
	long long atk = ATK;
	long long curHp = mid;

	int i;
	for (i = 0; i < N; i++) {
		auto [t, a, h] = Rooms[i];
		if (t == 1) {
			long long pac = (h % atk == 0 ? h / atk - 1 : h / atk);

			curHp -= pac * a;
			if (curHp <= 0) break;
		}
		else {
			atk += a;
			curHp = min(mid, curHp + h);
		}
	}

	return i == N;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> ATK;
	Rooms.assign(N, tuple<int, long long, long long>());

	for (int i = 0; i < N; i++) {
		int t, a, h;
		cin >> t >> a >> h;
		Rooms[i] = {t, a, h};
	}
	
	long long lo = 0;
	long long hi = 1e18;

	while (lo + 1 < hi) {
		long long mid = lo + (hi - lo) / 2;
		if (solve(mid))	hi = mid;
		else lo = mid;
	}
	cout << hi;
}