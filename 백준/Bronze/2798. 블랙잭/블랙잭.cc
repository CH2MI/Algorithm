#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int s = a[i] + a[j] + a[k];
				if (sum < s && s <= M) sum = s;
			}
		}
	}
	cout << sum;
	delete[] a;
}