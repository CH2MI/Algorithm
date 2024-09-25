#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	sort(v.begin(), v.end());

	priority_queue<int> pq;
	for (int i = 0; i < M; i++) {
		pq.push(0);
	}

	int mx = 0;
	for (auto itr = v.rbegin(); itr != v.rend(); itr++) {
		int t = pq.top();
		pq.pop();

		t = -t + *itr;
		mx = max(mx, t);
		pq.push(-t);
	}

	cout << mx;
}