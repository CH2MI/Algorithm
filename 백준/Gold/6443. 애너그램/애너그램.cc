#include <iostream>
#include <algorithm>
using namespace std;

string s;

void dfs() {
	do {
		cout << s << '\n';
	} while (next_permutation(s.begin(), s.end()));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> s;
		sort(s.begin(), s.end());
		dfs();
	}
}