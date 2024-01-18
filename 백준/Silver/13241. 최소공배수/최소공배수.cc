#include <iostream>
using namespace std;

int Euclidean(long long int a, long long int b) {
	if (b == 0)
		return a;
	return Euclidean(b, a % b);
}

int main() {
	long long int A, B;
	cin >> A >> B;
	cout << A * B / Euclidean(A, B) << '\n';
	
}