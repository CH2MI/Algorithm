#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		string s;
		int t;
		cin >> s;
		if (s == "push") {
			cin >> t;
			q.push(t);
		}
		else if (s == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s == "size") cout << q.size() << '\n';
		else if (s == "empty") cout << q.empty() << '\n';
		else if (s == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
		}
	}
}