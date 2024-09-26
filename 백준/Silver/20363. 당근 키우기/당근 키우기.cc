#include <iostream>
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;

	cout << X + Y + (min(X , Y) / 10);
}