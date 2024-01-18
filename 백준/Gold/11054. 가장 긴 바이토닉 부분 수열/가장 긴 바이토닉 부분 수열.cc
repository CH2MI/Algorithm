#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N + 2];
	int* inc = new int[N + 1]();
	int* dec = new int[N + 2]();
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	arr[0] = inc[0] = dec[0] = arr[N + 1] = dec[N + 1] = 0;
	for (int i = 1; i <= N; i++) {
		int inccnt = 0;
		int deccnt = 0;
		int i1 = N - i + 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				if (inc[j] > inccnt) inccnt = inc[j];
			
			int j1 = N - j + 1;
			if (arr[i1] > arr[j1]) 
				if (dec[j1] > deccnt) deccnt = dec[j1];
		}
		inc[i] = inccnt + 1;
		dec[i1] = deccnt + 1;
	}

	int m = 0;
	for (int i = 1; i <= N; i++) {	
		int sum = inc[i] + dec[i];
		if (m < sum) m = sum;
	}
	cout << m - 1;
}