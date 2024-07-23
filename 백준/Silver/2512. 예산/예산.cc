#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int mxsum;

bool solve(int mid) {
	int sum = 0;
	for (auto& i : v) {
		sum += min(mid, i);
	}

	return sum <= mxsum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	v = vector<int>(N);

	for (auto& i : v) cin >> i;

	cin >> mxsum;

	int lo = 1, hi = *max_element(v.begin(), v.end()) + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) lo = mid;
		else hi = mid;
	}

	cout << lo;
}