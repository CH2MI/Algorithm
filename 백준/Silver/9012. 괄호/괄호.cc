#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isVaild(string s) {
	stack<char> st;
	for (int j = 0; j < s.size(); j++) {
		if (s[j] == '(') st.push('(');
		else {
			if (st.empty()) {
				return false;
			}
			st.pop();
		}
	}
	return st.empty();

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (isVaild(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}