#include <iostream>
using namespace std;

int main() {
	int N, K, count = 0, t;
	cin >> N >> K;
	for (int i = 1; i <= N && count < K; i++) {
		if (N % i == 0) {
			count++;
			t = i;
		}
	}
	if (count < K) cout << "0";
	else cout << t;
}