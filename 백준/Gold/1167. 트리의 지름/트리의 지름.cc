#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int link;
	int dist;
	Node(int link = -1, int dist = -1) {
		this->link = link;
		this->dist = dist;
	}
};
struct Nodevector {
	vector<Node> N;
};

void dfs(vector<Nodevector>& v, vector<int>& visited, int start, int dist) {
	visited[start] = dist;

	for (auto i : v[start].N) {
		if (visited[i.link] == -1) {
			dfs(v, visited, i.link, dist + i.dist);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; 
	cin >> N;

	vector<Nodevector> v(N);

	for (int i = 0; i < N; i++) {
		int t1, t2, t3;
		cin >> t1;
		while (true) {
			cin >> t2;
			if (t2 == -1) break;
			cin >> t3;
			v[t1 - 1].N.emplace_back(t2 - 1, t3);
		}
	}

	// 임의의 한 점에서 dfs를 한다.
	vector<int> visited(N, -1);
	dfs(v, visited, 0, 0);
	int start = max_element(visited.begin(), visited.end()) - visited.begin();

	// 제일 먼 거리에서 dfs를 했을 때 제일 먼 거리가 트리의 지름이 된다.
	visited.assign(N, -1);
	dfs(v, visited, start, 0);
	cout << *max_element(visited.begin(), visited.end());
	
}