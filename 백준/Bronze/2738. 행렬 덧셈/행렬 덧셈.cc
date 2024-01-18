#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* a = new int[N * M];
	int* b = new int[N * M];
	int* s = new int[N * M];
	for (int i = 0; i < N * M; i++) cin >> a[i];
	for (int i = 0; i < N * M; i++) {
		cin >> b[i];
		s[i] = a[i] + b[i];
	}
	for (int i = 0; i < N * M; i++) {
		cout << s[i] << " ";
		if (i != 0 && (i + 1) % M == 0) cout << endl;
	}
}