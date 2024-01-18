#include <iostream>
using namespace std;

int Euclidean(long long int a, long long int b) {
	if (b == 0)
		return a;
	return Euclidean(b, a % b);
}

int main() {
	int a, b, c, d, A , B;
	cin >> a >> b >> c >> d;
	A = a * d + b * c;
	B = b * d;
	int t = Euclidean(A, B);
	cout << A / t << ' ' << B / t;
}