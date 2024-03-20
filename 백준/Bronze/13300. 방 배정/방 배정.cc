#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	int arr[6][2] = { 0 };
	for (int i = 0; i < N; i++) {
	    int a, b;
	    cin >> a >> b;
	    arr[b - 1][a]++;
	}
	
	int sum = 0;
	for (int i = 0; i < 6; i++) {
	    sum += (arr[i][0] + K - 1) / K + (arr[i][1] + K - 1) / K;
	}
	cout << sum;
}
