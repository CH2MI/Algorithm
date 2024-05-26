#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> parent;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	parent[B] = A;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> x(N), y(N), z(N);
	vector<tuple<int, int, int>> v;
	v.reserve(3 * N);

	parent.assign(N, 0);
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	// x, y, z를 개별로 받은 뒤 정렬한다.
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x[i] = { a, i };
		y[i] = { b, i };
		z[i] = { c, i };
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	// 인접한 x, y, z를 각각 차이를 구한뒤 정렬한다.
	for (int i = 0; i < N - 1; i++) {
		v.push_back({ abs(x[i].first - x[i + 1].first), x[i].second, x[i + 1].second });
		v.push_back({ abs(y[i].first - y[i + 1].first), y[i].second, y[i + 1].second });
		v.push_back({ abs(z[i].first - z[i + 1].first), z[i].second, z[i + 1].second });
	}

	sort(v.begin(), v.end());

	// 두 노드가 연결 되어있지 않으면 해당 간선을 선택한다.
	int sum = 0;
	for (auto& i : v) {
		auto [edge, node1, node2] = i;
		if (Find(node1) != Find(node2)) {
			Union(node1, node2);
			sum += edge;
		}
	}
	cout << sum;
}