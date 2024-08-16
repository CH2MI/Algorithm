#include <iostream>
#include <stack>
using namespace std;

int Parsing(string s) {
	stack<int> st;
	int ret = 0;

	for (auto i : s) {
		if (i == '(') st.push(-2);
		else if (i == '[') st.push(-3);
		else if (i == ')') {
			int t = 0;
			while (true) {
				if (st.empty()) return 0;
				int x = st.top();
				st.pop();
				if (x == -3) return 0;
				if (x != -2) t += x;
				else {
					if (!t) st.push(2);
					else st.push(t * 2);
					break;
				}
			}
		}
		else {
			int t = 0;
			while (true) {
				if (st.empty()) return 0;
				int x = st.top();
				st.pop();
				if (x == -2) return 0;
				if (x != -3) t += x;
				else {
					if (!t) st.push(3);
					else st.push(t * 3);
					break;
				}
			}
		} 
	}

	while (!st.empty()) {
		int x = st.top();
		st.pop();
		if (x == -3 || x == -2) return false;
		else ret += x;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	
	string s;
	cin >> s;

	cout << Parsing(s);
	
}