#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v, sum;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sum.push_back(v[0]);
	int maxsum = sum[0];
	for (int i = 1; i < n; i++) {
		int t = max(sum[i - 1] + v[i], v[i]);
		sum.push_back(t);
		if (t > maxsum) maxsum = t;
	}
	cout << maxsum;
}