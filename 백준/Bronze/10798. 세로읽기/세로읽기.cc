#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	for (int i = 0; i < 15; i++) {
		if (i < a.size()) cout << a[i];
		if (i < b.size()) cout << b[i];
		if (i < c.size()) cout << c[i];
		if (i < d.size()) cout << d[i];
		if (i < e.size()) cout << e[i];
	}
}