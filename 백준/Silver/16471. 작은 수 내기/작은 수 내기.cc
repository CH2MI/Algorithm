#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	vector<int> a(N), b(N);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int f = 1;
	for (int i = 0; i < N / 2 + 1; i++) {
		if (a[i] >= b[N / 2 + i]) f = 0;
	}
	if (f) cout << "YES";
	else cout << "NO";
}