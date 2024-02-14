#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	vector<long long> v(N + 1);
	v[0] = 0;
	v[1] = 1;

	for (int i = 2; i <= N; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v[N];
}