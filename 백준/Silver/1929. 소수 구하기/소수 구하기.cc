#include <iostream>
using namespace std;

int main() {
	int  M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (i == 1) continue;
		int j;
		for (j = 2; j * j <= i; j++) {
			if (i % j == 0) break;
		}
		if (j * j > i) cout << i << '\n';
	}
}