#include <iostream>
#include <cstring>
using namespace std;

int recursion(const char *s, int l, int r, int& count) {
	count++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1, count);
}

int isPalindrome(const char* s, int& count) {
	return recursion(s, 0, strlen(s) - 1, count);
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		char s[1001];
		cin >> s;
		int count = 0;
		cout << isPalindrome(s, count) << ' ' << count << '\n';
	}
}