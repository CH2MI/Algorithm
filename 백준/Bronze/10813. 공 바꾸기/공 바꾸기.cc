#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* barket = new int[N];

	for (int i = 0; i < N; i++)
		barket[i] = i + 1;

	for (int i = 0; i < M; i++) {
		int a, b, temp;
		cin >> a >> b;
		temp = barket[a - 1];
		barket[a - 1] = barket[b - 1];
		barket[b - 1] = temp;
	}

	for (int i = 0; i < N; i++)
		cout << barket[i] << " ";

	delete[] barket;
}