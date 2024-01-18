#include <iostream>
using namespace std;

int main() {
	int arr[21][21][21];
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (i == 0 || j == 0 || k == 0)
					arr[i][j][k] = 1;
				else if (i < j && j < k) arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
				else arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
			}
		}
	}
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;	
		int t;
		if (a <= 0 || b <= 0 || c <= 0) t = 1;
		else if (a > 20 || b > 20 || c > 20) t = arr[20][20][20];
		else t = arr[a][b][c];
		cout << "w(" << a << ", " << b  << ", " << c << ") = " << t << '\n';
	}
}