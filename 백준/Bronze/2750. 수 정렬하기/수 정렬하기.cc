#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; i++) 
		cin >> a[i];
	
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << a[i] << endl;
}