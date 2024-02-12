#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case) {
		string A, B;
		cin >> A >> B;
		string t;
		queue<pair<int, string>> q;
		vector<bool> visited(10000);
		int b = stoi(B);

		q.push({ stoi(A), t });
		while (!q.empty()) {
			auto t = q.front();
			q.pop();

			int a = t.first;

			if (a == b) {
				cout << t.second << '\n';
				break;
			}

			// 2배
			a = a * 2 % 10000;
			if (!visited[a]) {
				q.push({ a, t.second + 'D' });
				visited[a] = true;
			}

			// -1
			a = t.first;
			if (--a < 0) a = 9999;
			if (!visited[a]) {
				q.push({ a, t.second + 'S' });
				visited[a] = true;
			}

			// CIL
			a = t.first;
			a = (a % 1000) * 10 + (a / 1000);
			if (!visited[a]) {
				q.push({ a, t.second + 'L' });
				visited[a] = true;
			}

			// CIR
			a = t.first;
			a = (a % 10) * 1000 + (a / 10);
			if (!visited[a]) {
				q.push({ a, t.second + 'R' });
				visited[a] = true;
			}
		}
	}
}