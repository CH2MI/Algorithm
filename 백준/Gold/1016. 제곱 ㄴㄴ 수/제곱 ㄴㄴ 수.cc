#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long mn, mx;
	cin >> mn >> mx;
	vector<bool> v(mx - mn + 1, false);

	for (long long i = 2, ip = i * i; ip <= mx; i++, ip = i * i) {
		long long j = ((mn + ip - 1) / ip) * ip;
		while (j <= mx) {
			v[j - mn] = true;
			j += ip;
		}
	}

	int count = 0;
	for (int i = 0; i < mx - mn + 1; i++) {
		if (!v[i]) {
			count++;
		}
	}

	cout << count;
}