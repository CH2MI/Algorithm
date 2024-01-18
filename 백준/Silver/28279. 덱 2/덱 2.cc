#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	deque<int> d;
	for (int i = 0; i < N; i++) {
		int n, t;
		cin >> n;
		switch (n)
		{
		case 1:
			cin >> t;
			d.push_front(t);
			break;
		case 2:
			cin >> t;
			d.push_back(t);
			break;
		case 3:
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
			break;
		case 4:
			if (d.empty()) cout << "-1\n";
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
			break;
		case 5:
			cout << d.size() << '\n';
			break;
		case 6:
			cout << d.empty() << '\n';
			break;
		case 7:
			if (d.empty()) cout << "-1\n";
			else cout << d.front() << '\n';
			break;
		case 8:
			if (d.empty()) cout << "-1\n";
			else cout << d.back() << '\n';
			break;
		}
	}
}