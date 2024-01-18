#include <iostream>
using namespace std;

int main() {
	int t, max = 0, index;
	for (int i = 0; i < 9; i++) {
		cin >> t;
		if (max < t) {
			max = t;
			index = i + 1;
		}
	}
	cout << max << endl << index;
}