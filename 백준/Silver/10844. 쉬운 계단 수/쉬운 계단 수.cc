#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* dp = new int[N]();
	int** right = new int* [N];
	right[0] = new int[10]();
	dp[0] = 9;
	for (int i = 1; i < 10; i++) {
		right[0][i] = 1;
	}
	for (int i = 1; i < N; i++) {
		right[i] = new int[10]();
		for (int j = 0; j < 10; j++) {
			int t;
			if (j == 0) 
				t = right[i - 1][j + 1] % 1000000000;
			else if (j == 9) 
				t = right[i - 1][j - 1] % 1000000000;
			else {
				int t1 = right[i - 1][j - 1] % 1000000000;
				int t2 = right[i - 1][j + 1] % 1000000000;
				t = (t1 + t2) % 1000000000;
			}
			dp[i] = (dp[i] + t) % 1000000000;	
			right[i][j] = (right[i][j] + t) % 1000000000;
		}
	}
	cout << dp[N - 1];
}