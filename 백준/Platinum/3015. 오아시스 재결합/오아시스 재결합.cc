#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	int N;
	cin >> N;

	stack<pair<int, int>> st;

	long long count = 0;
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		int cnt = 1;
		while (!st.empty() && st.top().first <= H) {
			count += st.top().second;
			if (st.top().first == H) cnt += st.top().second;
			st.pop();
		}
		if (!st.empty()) count++;
		st.push({H, cnt});
	}

	cout << count;
}