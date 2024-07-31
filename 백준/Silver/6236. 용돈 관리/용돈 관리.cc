#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<int> list;

bool solve(int mid) {
	int m = 0;
	int curk = 0;
	for (const int i : list) {
		if (curk < i) {
			curk = mid;
			m++;
		}
		curk -= i;
	}

	return m <= M;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	list.assign(N, 0);
	for (auto& i : list)
		cin >> i;

	int lo = *max_element(list.begin(), list.end()) - 1, hi = INT_MAX;
	while (lo + 1 < hi) {
		int mid = lo + (hi - lo) / 2;
		if (solve(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;

}