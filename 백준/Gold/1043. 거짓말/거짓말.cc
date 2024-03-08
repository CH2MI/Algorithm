#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<set<int>> g;
vector<int> visited;
vector<vector<int>> party;

void dfs(int start) {
	visited[start] = 1;

	for (auto i : g[start]) {
		if (!visited[i]) dfs(i);
	}
}

bool f(int index) {
	for (auto i : party[index]) {
		if (visited[i - 1]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int M;
	cin >> N >> M;

	int T;
	cin >> T;

	vector<int> truth(T);
	for (int i = 0; i < T; i++) {
		cin >> truth[i];
	}

	// 파티에서 만났다면 간선으로 이어준다.
	g.assign(N, set<int>());
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;
		vector<int> v(c);
		for (int j = 0; j < c; j++) cin >> v[j];
		party.push_back(v);

		for (int j = 0; j < c - 1; j++) {
			for (int k = j + 1; k < c; k++) {
				g[v[j] - 1].insert(v[k] - 1);
				g[v[k] - 1].insert(v[j] - 1);
			}
		}
	}

	// 진실을 들어야하는 사람들은 모두 1로 체크한다.
	visited.assign(N, 0);
	for (auto i : truth) {
		dfs(i - 1);
	}

	// 거짓말을 할 수 있는 파티를 찾는다.
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (f(i)) ++cnt;
	}
	
	cout << cnt;
}