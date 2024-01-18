#include <iostream>
using namespace std;

struct section {
	int x1, y1;
	int x2, y2;
	section(int x1, int y1, int x2, int y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
};

void Recursion(char** arr, section s, int N) {
	if (N == 1) return;
	int n = N / 3;
	
	section a(s.x1, s.y1, s.x1 + n, s.y1 + n), b(a.x1 + n, a.y1, a.x2 + n, s.y2), c(b.x1 + n, b.y1, b.x2 + n, b.y2),
		d(a.x1, a.y1 + n, a.x2, a.y2 + n), e(d.x1 + n, d.y1, d.x2 + n, d.y2), f(e.x1 + n, e.y1, e.x2 + n, e.y2),
		g(d.x1, d.y1 + n, d.x2, d.y2 + n), h(g.x1 + n, g.y1, g.x2 + n, g.y2), i(h.x1 + n, h.y1, h.x2 + n, h.y2);

	for (int i = e.x1; i < e.x2; i++)
		for (int j = e.y1; j < e.y2; j++)
			arr[i][j] = ' ';

	Recursion(arr, a, n); Recursion(arr, b, n); Recursion(arr, c, n); Recursion(arr, d, n);
	Recursion(arr, f, n); Recursion(arr, g, n); Recursion(arr, h, n); Recursion(arr, i, n);
}

int main() {
	int N;
	cin >> N;
	char** arr = new char* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new char[N];
		for (int j = 0; j < N; j++)
			arr[i][j] = '*';
	}
	section s(0, 0, N, N);
	Recursion(arr, s, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

}