#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 20 * 50 + 1;
int arr[4] = {1, 5, 10, 50};
unordered_set<int> st;

void recursion(int N, int cnt, int sum, int k) {
	if (cnt == N) {
		st.insert(sum);
		return;
	}

	for (int i = k; i < 4; i++) {
		recursion(N, cnt + 1, sum + arr[i], i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	recursion(N, 0, 0, 0);
	cout << st.size();
}