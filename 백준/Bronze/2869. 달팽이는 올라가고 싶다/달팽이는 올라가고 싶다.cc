#include <iostream>
using namespace std;

int main() {
	int A, B, V, d;
	cin >> A >> B >> V;
	
	if (V == A) d = 1;
	else {
		V -= A;
		int t = A - B;
		d = V / t + 1;
		if (V % t != 0) d++;
	}
	cout << d;
}
