#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, b, a;
	cin >> n >> b >> a;

	vector<long long> v(n);
	long long sum = 0;

	for (auto& i : v) {
		cin >> i;
		sum += i;
	}

	sort(v.begin(), v.end());

	int hi = n;
	int lo = hi - a;

	for (int i = lo; i < hi; i++) {
		sum -= v[i] / 2;
	}

	while (lo > 0 && sum > b) {
		sum -= v[--hi] / 2;
		sum -= v[--lo] / 2;
	}

	while (lo < hi && sum > b) {
		sum -= v[--hi] / 2;
	}	

	cout << hi;
	
}