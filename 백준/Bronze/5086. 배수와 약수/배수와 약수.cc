#include <iostream>
using namespace std;

bool isDivisor(int a, int b) {
	if (a % b == 0) return true;
	return false;
}

int main() {
	while (true) {
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		if (N > M) {
			if (isDivisor(N, M)) cout << "multiple";
			else cout << "neither";
		}
		else if (N < M) {
			if (isDivisor(M, N)) cout << "factor";
			else cout << "neither";
		}
		else cout << "neither";
		cout << endl;
	}
}