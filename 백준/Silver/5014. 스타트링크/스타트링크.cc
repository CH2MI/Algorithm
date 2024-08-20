#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;

int BFS() {
	vector<int> visited(F);
	queue<pair<int, int>> q;
	q.push({ 0, S });

	while (!q.empty()) {
		auto [count, s] = q.front();
		q.pop();

		if (s == G) return count;

		int u = s + U;
		if (u >= 1 && u <= F && !visited[u - 1]) {
			visited[u - 1] = true;
			q.push({ count + 1, u });
		}
		int d = s - D;
		if (d >= 1 && d <= F && !visited[d - 1]) {
			visited[d - 1] = true;
			q.push({ count + 1, d });
		}
	}
	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	
	cin >> F >> S >> G >> U >> D;

	int answer = BFS();
	if (answer == -1) cout << "use the stairs";
	else cout << answer;
	
}