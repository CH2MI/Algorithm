#include <iostream>
using namespace std;

int main() {
	int N, t, max = -1000000, min = 1000000 ;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (max < t) max = t;
		if (min > t) min = t;
	}
	cout << min << " " << max;
}