#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	int B;
	cin >> N >> B;
	int sum = 0, b = 1;
	for (int i = N.size() - 1; i >= 0; i--, b *= B) {
		int t = N[i];
		if (t >= 65) t -= 55;
		else t -= 48;
		sum += b * t;
	}
	cout << sum;
}