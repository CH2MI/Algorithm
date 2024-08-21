#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	bool arr[1001] = { false };

	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (!arr[i]) {
			if (++cnt == K) {
				cout << i;
				return 0;
			}
			for (int j = i + i; j <= N; j += i) {
				if (arr[j]) continue;
				arr[j] = true;
				if (++cnt == K) {
					cout << j;
					return 0;
				}
			}
		}
	}
}