#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long C;
vector<int> v;

void Comb(vector<long long>& group, int l, int r, long long sum) {
	if (sum > C) return;
	if (l == r) {
		group.push_back(sum);
		return;
	}
	Comb(group, l + 1, r, sum + v[l]);
	Comb(group, l + 1, r, sum);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; 
	cin >> N >> C;
	v.assign(N, 0);

	for (auto& i : v) cin >> i;

	vector<long long> lgroup, rgroup;

	lgroup.reserve(pow(2, (N + 1) >> 1));
	rgroup.reserve(pow(2, (N + 1) >> 1));

		

	Comb(lgroup, 0, (N + 1) >> 1, 0);
	Comb(rgroup, (N + 1) >> 1, N, 0);

	sort(rgroup.begin(), rgroup.end());

	int cnt = 0;
	for (auto i : lgroup) {
		cnt += upper_bound(rgroup.begin(), rgroup.end(), C - i) - rgroup.begin();
	}
	cout << cnt;
}
