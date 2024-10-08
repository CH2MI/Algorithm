#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	int count = 0;
	for (const auto& c : s) {
		if (c == 'a') count++;
	}

	int len = s.size();

	int mn = (int)1e9;
	for (int i = 0; i < len; i++) {
		int cnt = 0;
		for (int j = i; j < i + count; j++) {
			if (s[j % len] == 'b') cnt++;
		}
		mn = min(cnt, mn);
	}
	cout << mn;
}