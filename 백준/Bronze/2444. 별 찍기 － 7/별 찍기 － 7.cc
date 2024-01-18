#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int n = 2 * N - 1;
	for (int i = 0; i < n; i++) {
		int M = N - i - 1;
		if (M < 0) M *= -1;

		for (int j = 0; j < M; j++) cout << " ";
		for (int j = 0; j < n - 2 * M; j++) cout << "*";
		cout << endl;
	}
}