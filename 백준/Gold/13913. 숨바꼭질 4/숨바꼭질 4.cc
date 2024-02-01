#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> visited(100001, -1);
	queue<pair<int, int>> q;
	q.push({ N, -2 });
	while (!q.empty()) {

		auto t = q.front();
		q.pop();

		// 이전 방문한 곳을 넣어준다.
		if (visited[t.first] == -1)
			visited[t.first] = t.second;

		if (t.first == K) {

			// 방문한 곳들을 스택에 넣어준다.
			stack<int> st;
			int i = t.first;
			while (visited[i] != -2) {
				st.push(i);
				i = visited[i];
			}
			st.push(i);

			// 스택에서 빼면서 출력한다.
			cout << st.size() - 1 << '\n';
			while (!st.empty()) {
				cout << st.top() << ' ';
				st.pop();
			}
			break;
		}
		t.second = t.first;

		// 방문하지 않은 좌표만 큐에 넣어준다.
		if (t.first * 2 < 100001 && visited[t.first * 2] == -1) q.push({ t.first * 2, t.second });
		if (t.first - 1 >= 0 && visited[t.first - 1] == -1) q.push({ t.first - 1, t.second });
		if (t.first + 1 < 100001 && visited[t.first + 1] == -1) q.push({ t.first + 1, t.second });
		

	}
}