#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> adj;
vector<int> visited;

bool dfs(int& start, int point, bool& cycle) {

	// 사이클이 생겼을 때
	if (visited[point]) {
		if (visited[point] == start + 1) {

			// 나를 빼고 사이클이 생겼다면?
			if (start != point) {
				start = point;
			}

			return true;
		}

		// 이미 완성된 사이클이면?
		else {
			return false;
		}
	}
	
	visited[point] = start + 1;
	int t = start;

	// 사이클이 생기지 않았거나, 생겼어도 일부인원이 안들어가면 방문 여부를 초기화해준다.
	if (dfs(start, adj[point], cycle)) {

		// 사이클에 들어가지 않는 탐색
		if (!cycle) visited[point] = -1;

		// 사이클의 마지막이면 이후 돌아갈 때는 사이클에 포함되지 않는다.
		if (start == point) cycle = false;
		return true;
	}

	visited[point] = 0;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> N;	
		adj.assign(N, 0);
		visited.assign(N, 0);

		for (int i = 0; i < N; i++) {
			cin >> adj[i];
			--adj[i];
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			
			// 사이클이 아니라고 확정 난 곳
			if (visited[i] == -1) cnt++;

			// 이미 포함된 곳은 제외
			if (visited[i]) continue;
			
			int t = i;
			bool cycle = true;

			// 사이클이 생겼을 때 
			if (dfs(t, t, cycle)) {

				// 사이클이 생겼지만 나를 포함하지 않으면 나는 팀이 없고, 사이클이 만들어진 곳은 다시 처리해준다.
				if (t != i) {
					cnt++;
					visited[i] = i + 1;
				}
			}

			// 사이클이 생기지 않았으면 나는 팀이 없다.
			else {
				cnt++;
				visited[i] = i + 1;
			}
		}
		cout << cnt << '\n';
	}
}