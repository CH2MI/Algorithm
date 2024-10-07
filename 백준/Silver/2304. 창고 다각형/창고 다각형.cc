#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N; cin >> N;
	vector<pair<int, int>> v(N);

	for (auto& [L, H] : v) cin >> L >> H;

	sort(v.begin(), v.end(), [](const pair<int, int>& A, const pair<int, int>& B) -> bool { return A.first < B.first; });

	int sum = 0;
	stack<int> st1, st2;

	// 단조 증가 방향으로 스택을 쌓으면서 계산한다.
	for (auto itr = v.begin(); itr != v.end(); itr++) {
		if (st1.empty()) st1.push(itr - v.begin());
		else if (v[st1.top()].second <= itr->second) {
			sum += (itr->first - v[st1.top()].first) * v[st1.top()].second;
			st1.push(itr - v.begin());
		}
	}

	// 역방향에서도 단조 증가 방향으로 스택을 쌓는다.
	for (auto itr = v.rbegin(); itr != v.rend(); itr++) {
		int index = std::distance(itr, v.rend()) - 1;
		if (st2.empty()) st2.push(index);
		else if (v[st2.top()].second < itr->second) {
			sum += (v[st2.top()].first - itr->first) * v[st2.top()].second;
			st2.push(index);
		}
	}

	cout << sum + v[st1.top()].second << '\n';
}