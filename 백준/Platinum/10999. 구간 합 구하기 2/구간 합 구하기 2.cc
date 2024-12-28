#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int sz = 1 << 20;
ll arr[sz << 1], lazy[sz << 1];

void propagate(int node, int ns, int ne) {
	if (!lazy[node]) return;

	if (node < sz) {
		lazy[node << 1] += lazy[node];
		lazy[node << 1 | 1] += lazy[node];
	}
	arr[node] += lazy[node] * (ne - ns + 1);
	lazy[node] = 0;
}

void update(int s, int e, ll k, int node = 1, int ns = 0, int ne = sz - 1) {
	propagate(node, ns, ne);

	if (ne < s || e < ns) return;
	if (s <= ns && ne <= e) {
		lazy[node] += k;
		propagate(node, ns, ne);
		return;
	}

	int mid = (ns + ne) >> 1;
	update(s, e, k, node << 1, ns, mid); update(s, e, k, node << 1 | 1, mid + 1, ne);
	arr[node] = arr[node << 1] + arr[node << 1 | 1];
}

ll query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
	propagate(node, ns, ne);

	if (ne < s || e < ns) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M, K; cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		ll n; cin >> n;
		update(i, i, n);
	}

	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a;
		if (a == 1) {
			ll d;
			cin >> b >> c >> d;
			update(b - 1, c - 1, d);
		}
		else {
			cin >> b >> c;
			cout << query(b - 1, c - 1) << '\n';
		}
	}
}