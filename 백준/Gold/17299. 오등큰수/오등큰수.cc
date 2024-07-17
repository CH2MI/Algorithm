#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000001
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	vector<int> v(N), cnt(MAX);

	for (auto& i : v) {
		cin >> i;
		cnt[i]++;
	}

	vector<int> answer(N);
	stack<int> st;

	for (int i = N - 1; i >= 0; i--) {
		if (st.empty()) {
			answer[i] = -1;
			st.push(v[i]);
		}

		else if (cnt[v[i]] < cnt[st.top()]) {
			answer[i] = st.top();
			st.push(v[i]);
		}

		else {
			st.pop();
			i++;
		}
	}

	for (const auto& i : answer) cout << i << ' ';
}