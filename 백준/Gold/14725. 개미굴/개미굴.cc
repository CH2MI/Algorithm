#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node {
	string name;
	map<string, int> childs;
};

vector<node> nodes;
int nindex = 1;

void DFS(int n, int cnt) {
	int len = cnt << 1;
	for (int i = 0; i < len; i++) {
		cout << '-';
	}
	if (n) cout << nodes[n].name << '\n';

	for (auto i : nodes[n].childs) {
		DFS(i.second, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	nodes.assign(15001, { "", map<string, int>() });
	

	int N; cin >> N;
	while (N--) {
		int M; cin >> M;
		int i = 0;
		while (M--) {
			string s; cin >> s;
			auto itr = nodes[i].childs.find(s);
			if (itr == nodes[i].childs.end()) {
				nodes[nindex].name = s;
				nodes[i].childs.insert({ s, nindex });
				i = nindex++;

			}
			else i = itr->second;
		}
	}
	DFS(0, -1);
}