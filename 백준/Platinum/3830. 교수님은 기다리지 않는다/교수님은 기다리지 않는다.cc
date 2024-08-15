#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> diff;

int Find(int x) {
	if (!parent[x]) return x;

	auto p = Find(parent[x]);
	diff[x] += diff[parent[x]];
	return parent[x] = p;
}

void Union(int a, int b, int w) {
	auto A = Find(a);
	auto B = Find(b);

	if (A == B) return;

	diff[A] = diff[b] - diff[a] + w;
	parent[A] = B;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true)
	{
		int N, M;
		cin >> N >> M;

		if (!N && !M) break;

		parent.assign(N + 1, 0);
		diff.assign(N + 1, 0);

		while (M--) {
			char c;
			int a, b, w;
			cin >> c;

			if (c == '!') {
				cin >> a >> b >> w;
				Union(a, b, w);
			}
			else {
				cin >> a >> b;
				auto A = Find(a);
				auto B = Find(b);

				if (A != B) cout << "UNKNOWN\n";
				else {
					cout << diff[a] - diff[b] << '\n';
				}
			}
		
		}
	}
}