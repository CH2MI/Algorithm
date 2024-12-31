#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll a) {
	ll l = (ll)log2(a);
	ll base = 2;
	ll cnt = 0;
	for (int i = 0; i <= l; i++, base <<= 1) {
		cnt += (a / base) * (base / 2);
		if (a % base >= base / 2) cnt += (a % base) - (base / 2) + 1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll A, B; cin >> A >> B;
	cout << solve(B) - solve(A - 1);
}