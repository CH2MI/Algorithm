#include <bits/stdc++.h>
using namespace std;

int N, M, S, cnt;
vector<int> sn, dt;
vector<vector<int>> adj;
stack<int> st;

int DFS(int cur) {
	int ret = dt[cur] = cnt++;
	st.push(cur);

	for (int& nxt : adj[cur]) {
		if (dt[nxt] == -1) ret = min(ret, DFS(nxt));
		else if (sn[nxt] == -1) ret = min(ret, dt[nxt]);
	}

	if (dt[cur] == ret) {
		while (1) {
			int u = st.top(); st.pop();
			sn[u] = S;
			if (u == cur) break;
		}
		S++;
	}
	return ret;
}

bool SCC() {
	S = cnt = 0;
	sn = dt = vector(N << 1, -1);

	for(int i = 0; i < N << 1; i++) if (dt[i] == -1) DFS(i);

	for (int i = 0; i < N; i++) if (sn[i * 2] == sn[i * 2 + 1]) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (cin >> N >> M) {
		adj.assign(N << 1, vector<int>());
		for (int i = 0; i < M; i++) {
			string s, e;
			cin >> s >> e;
			int a = s[0] == '-', b = e[0] == '-';
			int x = stoi(s.substr(1, s.size())) - 1, y = stoi(e.substr(1, s.size())) - 1;
			adj[x * 2 + !a].push_back(y * 2 + b);
			adj[y * 2 + !b].push_back(x * 2 + a);
		}
		cout << SCC() << '\n';
	}
}