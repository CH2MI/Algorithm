#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int Find(int n) {
	if (v[n] == n) return n;
	return v[n] = Find(v[n]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A < B)
		v[B] = A;
	else
		v[A] = B;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i <= n; i++)
		v.push_back(i);

	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c) {
			int A = Find(v[a]);
			int B = Find(v[b]);
			if (A == B) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			Union(a, b);
		}
	}
}