#include <bits/stdc++.h>
using namespace std;

int solve(string& s) {
	for (int i = 0; i < (int)s.size() / 2; i++) {
		if (s[i] != s[(int)s.size() - i - 1]) return 0;
	}
	return 1;
}

int main() {
	string s; cin >> s;
	if (solve(s)) cout << "true";
	else cout << "false";
}