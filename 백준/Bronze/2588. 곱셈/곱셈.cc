#include <iostream>
using namespace std;

int main() {
	int a, b, i, j;
	cin >> a >> b;
	i = b % 10;
	cout << a * i << endl;
	j = (b - i) / 10;
	i = j % 10;
	cout << a * i << endl;
	cout << a * (j / 10) << endl;
	cout << a * b << endl;
	return 0;
}