#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> v(N);

	for (auto& i : v) cin >> i;

	stack<int> st;
	vector<int> answer(N);
	
	for (int i = N - 1; i >= 0; i--) {

		// 스택에 값이 없으면 NGE(i)는 없다.
		if (st.empty()) {
			answer[i] = -1;
			st.push(v[i]);
		}

		// 스택의 top이 더 크면 NGE(i)가 된다.
		else if (st.top() > v[i]) {
			answer[i] = st.top();
			st.push(v[i]);
		}

		// 스택의 top이 같거나 작으면 pop을 하고 다시 비교해본다.
		else {
			st.pop();
			i++;
		}
	}

	for (auto i : answer) {
		cout << i << ' ';
	}
}