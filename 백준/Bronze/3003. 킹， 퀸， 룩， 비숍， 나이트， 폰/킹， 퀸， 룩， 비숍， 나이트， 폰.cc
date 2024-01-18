#include <iostream>
using namespace std;

int main() {
	int base[] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++) {
		int t;
		cin >> t;
		cout << base[i] - t << " ";
	}
}