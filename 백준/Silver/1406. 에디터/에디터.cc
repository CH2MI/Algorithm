#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	cin >> s;
	list<char> li;
	
	for (auto c : s) {
		li.push_back(c);
	}

	auto itr = li.end();

	int T;
	cin >> T;
	while (T--) {
		char c;
		cin >> c;

		switch (c) {
		case 'L': 
		{
			if (itr != li.begin()) itr--;
			break;
		}
		case 'D':
		{
			if (itr != li.end()) itr++;
			break;
		}
		case 'B':
		{
			if (itr != li.begin()) {
				auto tmp = itr--;
				li.erase(itr);
				itr = tmp;
			}
			break;
		}
		case 'P':
		{
			char t;
			cin >> t;
			li.insert(itr, t);
			break;
		}
		}
	}

	for (auto c : li) {
		cout << c;
	}
}