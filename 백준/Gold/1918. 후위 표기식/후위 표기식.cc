#include <stack>
#include <iostream>
#include <string>
using namespace std;

int get_priority(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default: return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	stack<char> st;
	getline(cin, s);
	
	int l = s.size();
	
	for (int i = 0; i < l; i++) {
		char c = s[i];
		int priority = get_priority(c);

		// +, -, *, / 이면 우선순위가 같거나 높은 연산자가 있다면 스택에서 모두 빼내고 넣는다.
		if (priority == 1 || priority == 2) {
			while (!st.empty() && get_priority(st.top()) >= priority) {
				cout << st.top();
				st.pop();
			}
			st.push(c);
		}

		// ( 은 그냥 넣는다.
		else if (c == '(') st.push(c);

		// )가 나오면 (가 나올때 까지 뺀다.
		else if (c == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();	
		}

		// 그 외에는 출력한다.
		else cout << c;
	}

	// 스택에 남아있는 것을 전부 뺀다.
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}