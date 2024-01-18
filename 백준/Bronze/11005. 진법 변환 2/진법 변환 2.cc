#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, B;
	string s;
	cin >> N >> B;
	while (N / B > 0) {
		int r = N % B;
		if (r > 9) r += 55;
		else r += 48;
		s.insert(0, 1, r);
		N /= B;
	}
	if (N > 9) N += 55;
	else N += 48;
	s.insert(0, 1, N);
	cout << s;
}