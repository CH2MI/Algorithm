#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	int a = N / 2 + 1, b = N / 2;

	vector<int> v(N);
	for (int i = 0; i < N; i += 2) v[i] = a++;
	for (int i = 1; i < N; i += 2) v[i] = b--;

	for (auto i : v) cout << i << ' ';
}