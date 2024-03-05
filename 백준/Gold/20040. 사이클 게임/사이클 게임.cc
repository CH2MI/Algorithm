#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	parent.reserve(n);
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
	}

	int result = m + 1;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		a = Find(a);
		b = Find(b);
		if (a == b) result = min(result, i);

		if (parent[a] <= parent[b])
			parent[parent[a]] = parent[b];
		else
			parent[parent[b]] = parent[a];
	}
	if (result == m + 1) cout << '0';
	else cout << result + 1;
}