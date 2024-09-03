#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> v(N), answer(N);

	for (auto& i : v) 
		cin >> i;
	
	stack<int> st;
	st.push(N - 1);

	for (int i = N - 2; i >= 0; i--) {
		while (!st.empty() && v[st.top()] < v[i]) {
			answer[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}

	for (auto i : answer)
		cout << i << ' ';
}