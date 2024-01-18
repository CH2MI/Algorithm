#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	b += c;
	while (b >= 60) {
		if (a == 23) a = 0;
		else a++;
		b -= 60;
	}
	cout << a << " " << b;
}