#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isVaild(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') st.push(s[i]);
		else if (s[i] == ')') {
			if (st.empty()) return false;
			else if (st.top() != '(') return false;
			st.pop();
		}
		else if (s[i] == ']') {
			if (st.empty()) return false;
			else if (st.top() != '[') return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		string s;
		getline(cin, s);
		if (s[0] == '.') break;
		if (isVaild(s)) cout << "yes\n";
		else cout << "no\n";
	}
}