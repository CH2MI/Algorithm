#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> parent, dist;

int Find(int x) {
	if (!parent[x]) return x;

	int p = Find(parent[x]);
	dist[x] += dist[parent[x]];
	return parent[x] = p;
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) return;

	dist[A] = dist[b] - dist[a] + (abs(a - b) % 1000);
	parent[A] = B;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	
	while (T--) {
		cin >> N;

		parent.assign(N + 1, 0);
		dist.assign(N + 1, 0);

		while (true) {
			char c;
			cin >> c;

			if (c == 'O') break;

			int I, J;

			if (c == 'E') {
				cin >> I;
				Find(I);
				cout << dist[I] << '\n';
			}
			else {
				cin >> I >> J;
				Union(I, J);
			}
		}
	}
}
