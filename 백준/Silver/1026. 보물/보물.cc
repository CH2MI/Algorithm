#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N;
	cin >> N;

	vector<int> a(N), b(N);

	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;
}