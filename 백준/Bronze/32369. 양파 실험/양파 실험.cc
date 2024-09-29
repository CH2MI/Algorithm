#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, A, B;
	cin >> N >> A >> B;

	int a = 1, b = 1;

	for (int i = 0; i < N; i++) {
		a += A;
		b += B;
		if (a < b) swap(a, b);
		else if (a == b) b--;
	}
	cout << a << ' ' << b;
}
