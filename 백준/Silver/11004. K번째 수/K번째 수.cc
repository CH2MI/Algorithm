#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	cout << v[K - 1];
}