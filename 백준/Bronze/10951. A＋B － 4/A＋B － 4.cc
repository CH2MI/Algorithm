#include <iostream>
using namespace std;

int main() {
	int a, b, t;
	while ((a = cin.get()) != EOF) {
		a -= 48;
		cin >> b;
		cout << a + b << endl;
		t = cin.get();
	}
}