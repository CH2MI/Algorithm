	#include <iostream>
	#include <queue>
	using namespace std;

	long long A, B;

	int bfs() {
		priority_queue<pair<int, long long>> q;
		vector<bool> visited(B + 1);
		q.push({ 0, A });
		while (!q.empty()) {
			auto t = q.top();
			q.pop();
		
			if (t.second == B) return -t.first + 1;

			visited[t.second] = 1;

			long long t1 = t.second << 1;
			if (t1 <= B && !visited[t1])
				q.push({ t.first - 1, t1 });

			long long t2 = t.second * 10 + 1;
			if (t2 <= B && !visited[t2])
				q.push({ t.first - 1, t2 });
		}

		return -1;
	}

	int main() {
		ios_base::sync_with_stdio(false); cin.tie(NULL);
	
		cin >> A >> B;

		cout << bfs();
	}