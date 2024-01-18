#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int a, b, c, d;
	a = x;
	b = w - x;
	c = y;
	d = h - y;
	cout << min(min(a, b), min(c, d));
}