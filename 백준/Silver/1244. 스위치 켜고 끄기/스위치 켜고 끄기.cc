#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bool v[101] = { false, };
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		if (t) v[i] = true;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int g, t;
		cin >> g >> t;

		if (g == 1) {
			for (int j = t; j <= N; j += t) {
				v[j] = !v[j];
			}
		}

		else {
			v[t] = !v[t];
			for (int j = 1; t - j >= 1 && t + j <= N; j++) {
				if (v[t - j] != v[t + j]) break;
				v[t - j] = !v[t - j];
				v[t + j] = !v[t + j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i != 1 && i % 20 == 1) cout << '\n';
		cout << v[i] << ' ';
	}
}