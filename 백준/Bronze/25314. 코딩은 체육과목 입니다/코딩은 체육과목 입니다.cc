#include <iostream>
using namespace std;

int main() {
	int N;
	int count;
	cin >> N;
	count = N / 4;
	for (int i = 0; i < count; i++) {
		cout << "long ";
	}
	cout << "int";
}