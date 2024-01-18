#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		double result = 1;
		for (int i = M ; i > M - N; i--) {
			result = result * i / (M - i + 1);
		}
		cout << (int)result << '\n';
	}
}