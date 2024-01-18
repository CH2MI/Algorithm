#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int A, int B, int C, int n) {
	if (n == 0) return;
	hanoi(A, C, B, n - 1);
	cout << A << ' ' << C << '\n';
	hanoi(B, A, C, n - 1);
 }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';
	int A = 1, B = 2, C = 3;
	hanoi(A, B, C, n);
}