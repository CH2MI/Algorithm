#include <iostream>
using namespace std;

int main() {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	int fn = a1 * n0 + a0;
	int gn = c * n0;
	if (fn <= gn && a1 <= c) cout << '1';
	else cout << '0';
}