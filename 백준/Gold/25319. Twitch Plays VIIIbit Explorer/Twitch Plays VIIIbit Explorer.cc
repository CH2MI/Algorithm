#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, S;
string name;
vector<string> adj;
vector<vector<pair<int, int>>> Hash;

string Caldist(int i, int j, int x, int y) {
	string ret;

	int tx = x - i;
	int ty = y - j;

	int xcnt = abs(tx);
	int ycnt = abs(ty);

	if (tx < 0)
		while (xcnt--) ret.push_back('R');
	else
		while (xcnt--) ret.push_back('L');

	if (ty < 0)
		while (ycnt--) ret.push_back('D');
	else
		while (ycnt--) ret.push_back('U');

	ret.push_back('P');
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> S;

	adj.assign(N, string());

	vector<int> alpabets(26);
	vector<int> names(26);
	Hash.assign(26, vector<pair<int, int>>());

	for (int i = 0; i < N; i++) {
		cin >> adj[i];

		for (int j = 0; j < M; j++) {
			alpabets[adj[i][j] - 'a']++;

			Hash[adj[i][j] - 'a'].push_back({ j, i });
		}
	}

	cin >> name;

	for (auto& i : name) {
		names[i - 'a']++;
	}

	// 몇번 강화할 수 있는지 구하기
	int C = 1e9;

	for (int i = 0; i < 26; i++) {
		if (names[i]) {
			C = min(C, alpabets[i] / names[i]);
		}
	}

	string ret;
	int x = 0, y = 0;

	for (int cnt = 0; cnt < C; cnt++) {
		for (auto& c : name) {

			// 제일 짧은 거리를 찾아준다. 선택한 거리는 지워야 한다.
			int dist = 1e9;
			vector<pair<int, int>>::iterator coord;
			vector<pair<int, int>>& v = Hash[c - 'a'];
			
			for(auto itr = v.begin(); itr != v.end(); itr++) {
				int tmp = abs(itr->first - x) + abs(itr->second - y);

				if (tmp < dist) {
					coord = itr;
					dist = tmp;
				}
			}

			ret.append(Caldist(coord->first, coord->second, x, y));
			x = coord->first;
			y = coord->second;
			v.erase(coord);
			adj[y][x] = '.';
		}
	}

	ret.append(Caldist(M - 1, N - 1, x, y));
	ret.erase(ret.end() - 1);

	cout << C << ' ' << ret.size() << '\n';
	cout << ret;
}

