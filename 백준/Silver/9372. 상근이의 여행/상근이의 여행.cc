#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		int a, b;
		for (int i = 0; i < M; i++) cin >> a >> b;
		cout << N - 1 << '\n';
	}
}