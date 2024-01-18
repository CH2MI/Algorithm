#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n, t;
		cin >> n;
		switch (n)
		{
		case 1:
			cin >> t;
			s.push(t);
			break;
		case 2:
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else cout << "-1\n";
			break;
		case 3:
			cout << s.size() << '\n';
			break;
		case 4:
			cout << s.empty() << '\n';
			break;
		case 5:
			if (!s.empty()) {
				cout << s.top() << '\n';
			}
			else cout << "-1\n";
			break;
		}
	}
}