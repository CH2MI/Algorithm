#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B;
	int a, b;
	cin >> A >> B;

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	a = stoi(A);
	b = stoi(B);

	if (A > B) cout << A;
	else cout << B;
}