#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	int R = N / 5, Q = N % 5;
	while (R >= 0) {
		if (Q == 0 || Q % 3 == 0) {
			count = R + Q / 3;
			break;
		}
		R--;
		Q += 5;
	}
	if (R == -1 && (Q % 3 != 0 || N % 3 != 0)) cout << "-1";
	else cout << count;
}