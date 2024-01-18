#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void cantor(string& s, int l, int r, int n) {
	if (n == -1) 
		return;
	int t = (int)pow(3, n - 1);
	int t1 = l + t;
	int t2 = t1 + t;
	for (int i = t1; i < t2; i++) {
		s[i] = ' ';
	}
	cantor(s, l, t1, n - 1);
	cantor(s, t2, r, n - 1);
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string s;

	while(getline(cin, s)) {
		if (s.empty()) break;
		int n = stoi(s);
		int N = pow(3, n);
		s.clear();
		for (int i = 0; i < N; i++)
			s.push_back('-');
		cantor(s, 0, s.size(), n);
		cout << s << '\n';
	}
}