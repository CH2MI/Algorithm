#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int m = max(max(a, b), c);
	int t = a + b + c - m;
	if (m < t) cout << a + b + c;
	else cout << t + t - 1;
}