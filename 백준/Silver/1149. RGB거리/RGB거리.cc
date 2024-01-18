#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int** arr = new int* [N];
	int** sum = new int* [N];
	for (int i = 0; i < N; i++) {
		int R, G, B;
		cin >> R >> G >> B;
		arr[i] = new int[3];
		sum[i] = new int[3];
		arr[i][0] = R; arr[i][1] = G; arr[i][2] = B;
	}
	sum[0][0] = arr[0][0]; sum[0][1] = arr[0][1]; sum[0][2] = arr[0][2];

	int s = min({ sum[0][0], sum[0][1], sum[0][2] });
	for (int i = 1; i < N; i++) {
		sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + arr[i][0];
		sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + arr[i][1];
		sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + arr[i][2];
		s = min({ sum[i][0], sum[i][1], sum[i][2] });
	}
	cout << s;
}