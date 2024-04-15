#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int R[1001] = { 0 };
	int G[1001] = { 0 };
	int B[1001] = { 0 };

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		R[i] = min(G[i - 1], B[i - 1]) + a;
		G[i] = min(R[i - 1], B[i - 1]) + b;
		B[i] = min(R[i - 1], G[i - 1]) + c;
	}
	cout << min({ R[N], G[N], B[N] });	
}