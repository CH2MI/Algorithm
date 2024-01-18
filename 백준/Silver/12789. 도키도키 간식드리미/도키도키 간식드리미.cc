#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isVaild(stack<int> st, int l) {
	stack<int> tmp;
	int i;
	for (i = 1; i <= l; i++) {
		if (!st.empty() && i == st.top()) st.pop();
		else if (tmp.empty()) {
			tmp.push(st.top());
			st.pop();
			i--;
		}
		else if (i == tmp.top()) tmp.pop();
		else if (st.top() > tmp.top()) return false;
		else {
			tmp.push(st.top());
			st.pop();
			i--;
		}
	}
	return i > l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	stack<int> st;
	for (int i = v.size() - 1; i >= 0; i--) {
		st.push(v[i]);
	}
	if (isVaild(st, N)) cout << "Nice";
	else cout << "Sad";
}