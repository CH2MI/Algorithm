#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	getline(cin, s);

	string t;
	char prev = '0';
	for (auto c : s) {
		if (prev == '&' || prev == '|') {
			prev = '0';
			continue;
		}

		switch (c)
		{
		case '<': case '>': case '(': case ')':
			if (!t.empty()) cout << t << ' ';
			t.clear();
			cout << c << ' ';
			break;
		case '&': case '|':
			if (!t.empty()) cout << t << ' ';
			t.clear();
			prev = c;
			cout << c << c << ' ';
			break;
		case ' ':
			if (!t.empty()) cout << t << ' ';
			t.clear();
			break;
		default:
			t.push_back(c);
			break;
		}
	}
	if (!t.empty()) cout << t << ' ';
}