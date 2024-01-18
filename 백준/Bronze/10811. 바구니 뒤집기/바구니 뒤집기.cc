#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* barket = new int[N];

	for (int i = 0; i < N; i++)
		barket[i] = i + 1;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int size = b - a + 1;
		int* temp = new int[size];
		for (int j = 0; j < size; j++) {
			temp[j] = barket[b - j - 1];
		}
		
		for (int j = 0; j < size; j++) {
			barket[a + j - 1] = temp[j];
		}
		delete[] temp;
	}

	for (int i = 0; i < N; i++)
		cout << barket[i] << " ";

	delete[] barket;
}