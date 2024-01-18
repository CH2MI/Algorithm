#include <iostream>
using namespace std;

int main() {
	int N, count = 1, a = 1, b = 1;
	bool decrease = true;
	cin >> N;
	while (N > count) {
		if (a == 1 && decrease) {
			b++;
			decrease = false;
		}
		else if (b == 1 && !decrease) {
			a++;
			decrease = true;
		}
		else if (a == 1 || !decrease) {
			a++; b--;
		}		
		else {
			a--; b++;
		}
		count++;
	}
	cout << a << '/' << b;
}
