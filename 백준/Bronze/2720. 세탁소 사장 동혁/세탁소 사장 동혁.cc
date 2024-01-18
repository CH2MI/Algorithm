#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, q, d, n, p;
		cin >> c;
		q = c / 25;
		if (c > 0) c -= 25 * q;
		d = c / 10;
		if (c > 0) c -= 10 * d;
		n = c / 5;
		if (c > 0) c -= 5 * n;
		p = c;
		cout << q << " " << d << " " << n << " " << p << endl;
	}
}