#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;

	int a, b;
	cin >> a >> b;
	n -= 2;
	while (n--) {
		int k; cin >> k;

		if (a == b) a += k;
		else if (a < b) a += k;
		else b += k;
	}

	int diff = abs(a - b);
	int cnt = 0;

	cnt += diff / 100;
	diff %= 100;
	cnt += diff / 50;
	diff %= 50;
	cnt += diff / 20;
	diff %= 20;
	cnt += diff / 10;
	diff %= 10;
	cnt += diff / 5;
	diff %= 5;
	cnt += diff / 2;
	diff %= 2;
	cnt += diff;

	cout << cnt;

}