#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		if (!((n + 1) % (n % 100))) cout << "Good\n";
		else cout << "Bye\n";
	}
}