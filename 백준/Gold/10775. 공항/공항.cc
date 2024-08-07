#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int Find(int x) {
	if (v[x] == -1) return x;
	return v[x] = Find(v[x]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) return;
	v[A] = B;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int G, P;
	cin >> G >> P;

	v = vector<int>(G + 1, -1);

	int i;
	for (i = 0; i < P; i++) {
		int g; 
		cin >> g;

		int t = Find(g);
		if (t == 0) break;

		Union(t, t - 1);
	}
	cout << i;
}