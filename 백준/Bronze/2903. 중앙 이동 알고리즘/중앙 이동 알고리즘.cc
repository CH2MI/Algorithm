#include <iostream>
using namespace std;

int main() {
	int N, dot = 2, r = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		dot += r;
		r *= 2;
	}
	cout << dot * dot;
}