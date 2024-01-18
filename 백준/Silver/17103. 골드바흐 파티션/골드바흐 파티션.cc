#include <iostream>
#include <vector>
using namespace std;

int main() {
	bool a[1000001] = { false };
	a[0] = a[1] = true;
	vector<int> v;
	for (int i = 2; i <= 1000000; i++) {
		if (!a[i]) {
			for (int j = i + i; j <= 1000000; j += i) a[j] = true;
			v.push_back(i);
		}
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		int l = v.size(), s = 0, count = 0;
		for (int j = 0; j < l && v[j] < n; j++) {
			int t = v[j];
			if (!a[n - t]) {
				count++;
				if (n - t == t) count++;
			} 
		}
		cout << count / 2 << '\n';
	}
}