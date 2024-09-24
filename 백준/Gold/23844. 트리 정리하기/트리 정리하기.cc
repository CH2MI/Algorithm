#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> tree;
vector<int> childs;
vector<int> parent;
vector<vector<int>> level(10000);
int mxlevel = 0;

int make_tree(int p, int n, int l) {
	int cnt = 0;

	parent[n] = p;
	level[l].push_back(n);
	mxlevel = max(mxlevel, l);
	
	for (const auto& i : tree[n]) {
		if (i == p) continue;
		cnt += make_tree(n, i, l + 1);
	}

	childs[n] = cnt;
	return cnt + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N >> K;

	tree.assign(N, vector<int>());
	childs.assign(N, -1);
	parent.assign(N, -1);

	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s - 1].push_back(e - 1);
		tree[e - 1].push_back(s - 1);
	}

	make_tree(-1, 0, 0);

	for (int i = mxlevel; i >= 0; i--) {

		// 트리의 두께가 K 이하가 될 때까지 반복한다.
		// 노가다긴 한데 TLE안난다고 믿어요...
		while (level[i].size() > K) {
			int mn = 10000;
			auto t = level[i].begin();

			// 자식의 개수가 최소인 노드를 찾는다.
			for (auto itr = level[i].begin(); itr != level[i].end(); itr++) {
				if (childs[*itr] < mn) {
					t = itr;
					mn = childs[*itr];
				}
			}

			// 해당 노드를 지우려면 부모들도 알아야 한다.
			int value = *t;
			int cnt = childs[value] + 1;
			int p = parent[value];
			while (p != -1) {
				childs[p] -= cnt;
				p = parent[p];
			}

			// 해당 노드를 지운다.
			parent[value] = -1;
			level[i].erase(t);
		}
	}
	cout << childs[0] + 1;
}