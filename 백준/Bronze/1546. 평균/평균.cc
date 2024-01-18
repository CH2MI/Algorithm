#include <iostream>
using namespace std;

int main() {
	int N, max = 0;
	cin >> N;
	int* a = new int[N];

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		a[i] = t;
		if (t > max) max = t;
		
	}

	float sum = 0;
	float average;
	for (int i = 0; i < N; i++) {
		sum += (float)a[i] / max * 100;
	}
	average = (float)sum / N;
	cout << average;
}