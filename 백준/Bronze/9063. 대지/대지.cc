#include <iostream>
using namespace std;

int main() {
	int maxx = -10000, maxy = -10000, minx = 10000, miny = 10000;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		if (maxx < x) maxx = x;
		if (minx > x) minx = x;
		if (maxy < y) maxy = y;
		if (miny > y) miny = y;
	}
	cout << (maxx - minx) * (maxy - miny);
}