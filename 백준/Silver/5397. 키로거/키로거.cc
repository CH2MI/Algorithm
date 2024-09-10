#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	while (N--) {
		string s;
		cin >> s;

		list<char> li;
		auto cursor = li.end();
		for (const auto& c : s) {
			if (c == '<') {
				if (cursor != li.begin()) cursor--;
			}

			else if (c == '>') {
				if (cursor != li.end()) cursor++;
			}

			else if (c == '-') {
				if (cursor != li.begin()) {
					cursor = li.erase(--cursor);
				}
			}
			
			else {
				li.insert(cursor, c);
			}
		}

		for (const auto& c : li) {
			cout << c;
		}
		cout << '\n';
	}
}