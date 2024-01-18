#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long int t;
		cin >> t;
		if (t == 0 || t == 1) {
			cout << "2\n";
			continue;
		}
		long long int j = t;
		while (true) {
			long long int k;
			for (k = 2; k * k <= j; k++) {
				if (j % k == 0) break;
			}
			if (k * k > j) {
				cout << j << '\n';
				break;
			}
			j++;
		}
	}
}