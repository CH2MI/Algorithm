#include <iostream>
using namespace std;

int Euclidean(int a, int b) {
	if (b == 0)
		return a;
	return Euclidean(b, a % b);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;
		cout << A * B / Euclidean(A, B) << '\n';
	}
}