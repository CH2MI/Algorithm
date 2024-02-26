#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void a() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		auto b = binary_search(v.begin(), v.end(), t);
		if (b) cout << "1\n";
		else cout << "0\n";
	}
}

void b() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s.insert(t);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		auto b = s.count(t);
		if (b) cout << "1\n";
		else cout << "0\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	a();
}