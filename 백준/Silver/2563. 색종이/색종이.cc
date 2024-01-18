#include <iostream>
using namespace std;

int main() {
	int area[100][100] = { 0, };
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		for (int j = r; j < r + 10; j++) 
			for (int k = c; k < c + 10; k++) 
				area[j][k] = 1;	
	}
	int sum = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (area[i][j] == 1) sum++;

	cout << sum;
}