#include <iostream>
using namespace std;


int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int i, j;
	for (i = -999; i < 1000; i++) {
		for (j = -999; j < 1000; j++) {
			if ((a * i + b * j == c) && (d * i + e * j == f)) break;
		}
		if (j < 1000) break;
	}
	cout << i << ' ' << j;	
}