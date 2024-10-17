#include <iostream>
using namespace std;

bool recursion(string& s, int left, int right) {
	if (left == right) return true;

	int l = left, r = right;

	while (l < r) {
		if (s[l] == s[r]) return false;
		else l++, r--;
	}
	return recursion(s, left, r- 1);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	while (N--) {
		string s; cin >> s;
		int len = s.size();

		if (recursion(s, 0, len - 1)) cout << "YES\n";
		else cout << "NO\n";
	}
}