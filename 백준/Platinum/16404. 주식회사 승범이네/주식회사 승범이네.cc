#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 18;
int arr[sz << 1];
vector<array<int, 2>> euler;
vector<vector<int>> adj;

void update(int s, int e, int k, int node = 1, int ns = 0, int ne = sz - 1) {
	if (e < ns || ne < s) return;
	if (s <= ns && ne <= e) {
		arr[node] += k;
		return;
	}

	int mid = (ns + ne) >> 1;
	update(s, e, k, node << 1, ns, mid); update(s, e, k, node << 1 | 1, mid + 1, ne);
}

int query(int x) {
	int i = x + sz;
	int sum = 0;
	while (i >= 1) {
		sum += arr[i];
		i >>= 1;
	}
	return sum;
}

void euler_tour(int cur, int& cnt) {
	euler[cur][0] = cnt++;

	for (int& nxt : adj[cur]) euler_tour(nxt, cnt);

	euler[cur][1] = cnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;
	euler.assign(N, array<int, 2>());
	adj.assign(N, vector<int>());

	for (int i = 0; i < N; i++) {
		int s; cin >> s;
		if (s == -1) continue;
		adj[s - 1].push_back(i);
	}

	int cnt = 0;
	euler_tour(0, cnt);

	for (int i = 0; i < M; i++) {
		int q, s, w; cin >> q;
		if (q == 1) {
			cin >> s >> w;
			update(euler[s - 1][0], euler[s - 1][1], w);
		}
		else {
			cin >> s;
			cout << query(euler[s - 1][0]) << '\n';
		}
	}
}