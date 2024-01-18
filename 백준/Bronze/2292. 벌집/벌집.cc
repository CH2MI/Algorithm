#include <iostream>
using namespace std;

int main() {
	int N, r = 0, t = 1, count = 0;
	cin >> N;
	while (N > t || count == 0) {
		t += r;
		r += 6;
		count++;
	}
	cout << count;
}