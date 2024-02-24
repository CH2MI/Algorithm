#include <iostream>
using namespace std;

long long solve(int A, int B, int C) {
	if (B == 1) return A % C;

	long long ret = solve(A, B / 2, C);

	if (B % 2 == 0) 
		return (ret * ret) % C;
	else 
		return (ret * ret % C) * A % C;
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;
	cout << solve(A, B, C);
}