#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

multiset<int> backpack;
priority_queue<pair<int, int>> pq;
int N, K;

long long calculate() {
	int cnt = K;
	long long sum = 0;

	while (!pq.empty() && cnt) {
		auto i = pq.top();
		pq.pop();

		// 보석을 배낭에 담을 수 있는 지 확인한다.
		auto itr = backpack.lower_bound(i.second);

		// 못담으면 넘어간다.
		if (itr == backpack.end()) continue;

		sum += (long long)i.first;
		backpack.erase(itr);
		--cnt;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int M, V;
		cin >> M >> V;
		pq.emplace(V, M);
	}

	for (int i = 0; i < K; i++) {
		int C;
		cin >> C;
		backpack.insert(C);
	}

	cout << calculate();
}