#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	stack<char> st;
	bool isTag = false;
	string s;
	getline(cin, s);
	for (auto c : s) {
		if (c == '<') {
			isTag = true;

			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}

			cout << c;
		}
		else if (c == ' ') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}

			cout << c;
		}
		else if (c == '>') {
			isTag = false;
			cout << c;
		}
		else if (isTag) {
			cout << c;
		}
		else {
			st.push(c);
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}