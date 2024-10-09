#include <iostream>
#include <vector>
using namespace std;

int n, k;

bool Is_Rainbow(vector<int>& p) {
	for (int i = 1; i <= k; i++) {
		if (!p[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;

	vector<int> v(n), p(k + 1), np(k + 1);
	for (int& i : v) {
		cin >> i;
		p[i]++;
	}

	int l = 0, r = 1;
	int mn = (int)1e9;
	np[v[0]]++;
	p[v[0]]--;
	while (r < n) {
		if (Is_Rainbow(np)) {
			if (Is_Rainbow(p)) {
				mn = min(r - l, mn);

				np[v[l]]--;
				p[v[l]]++;
				l++;
			}
			else {
				np[v[l]]--;
				p[v[l]]++;
				l++;
				
			}
		}
		else {
			np[v[r]]++;
			p[v[r]]--;
			r++;
		}
	}

	while (Is_Rainbow(p) && Is_Rainbow(np)) {
		mn = max(r - l, mn);
		np[v[l]]--;
		p[v[l]]++;
		l++;
	}

	if (mn == (int)1e9) cout << '0';
	else cout << mn;
}