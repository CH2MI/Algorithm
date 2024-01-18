#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int *barket = new int[N];
	
	for (int i = 0; i < N; i++) 
		barket[i] = 0;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a - 1; j < b; j++) 
			barket[j] = c;
	}

	for (int i = 0; i < N; i++) 
		cout << barket[i] << " ";

	delete[] barket;
}