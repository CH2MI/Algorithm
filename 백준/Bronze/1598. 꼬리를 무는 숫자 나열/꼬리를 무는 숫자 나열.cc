#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	--N; --M;

	cout << abs(M / 4 - N / 4) + abs(M % 4 - N % 4);
}
