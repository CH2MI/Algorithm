#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	long long int* a = new long long int[N + 1];
	for (int i = 1; i <= N; i++) {
		if (i == 1) a[i] = 1;
		else if (i == 2) a[i] = 2;
		else a[i] = (a[i - 1] + a[i - 2]) % 15746;
	}
	cout << a[N];
}