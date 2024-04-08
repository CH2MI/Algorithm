#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
string s;

void dfs(string t, int cnt, int c, int v, int k) {
	if (cnt == L) {
		if (c >= 1 && v >= 2)
			cout << t << '\n';
		return;
	}

	for (int i = k + 1; i < C; i++) {
		t.push_back(s[i]);
		switch (s[i]) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			dfs(t, cnt + 1, c + 1, v, i);
			break;
		default: 
			dfs(t, cnt + 1, c, v + 1, i);
		}
		t.erase(t.end() - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> L >> C;
	
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		s.push_back(c);
	}

	sort(s.begin(), s.end());

	string t;
	dfs(t, 0, 0, 0, -1);
}