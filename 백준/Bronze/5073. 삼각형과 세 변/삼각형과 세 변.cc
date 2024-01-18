#include <iostream>
using namespace std;

int main() {
	while (true) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0) break;
		int m = max(max(x, y), z);
		int sum = x + y + z;
		if (sum - m <= m) cout << "Invalid";
		else if (x == y && y == z) cout << "Equilateral";
		else if (x == y || y == z || z == x) cout << "Isosceles";
		else cout << "Scalene";
		cout << endl;
	}
}