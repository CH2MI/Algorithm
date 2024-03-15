#include <iostream>
#include <vector>
using namespace std;

vector<string> v;

void recursion(int N, int x, int y) {
	if (N == 1) return;
	int mx = x + N / 2;
	int my1 = y - N / 2;
	int my2 = y + N / 2;
	
	for (int i = mx; i < N / 2 + mx; i++) {
		for (int j = my1 + 1 + i - mx; j < my2 - i + mx; j++) {
			v[i][j] = ' ';
		}
	}

	recursion(N / 2, x, y);
	recursion(N / 2, mx, my1);
	recursion(N / 2, mx, my2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N;
	cin >> N;
	v.assign(N, string((N << 1) + 1, ' '));

	for (int i = 0; i < N; i++) {
		for (int j = N - i; j < N + i + 1; j++)
			v[i][j] = '*';
	}

	recursion(N, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < (N << 1) + 1; j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
}