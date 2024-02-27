#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (const pair<long long, long long>& A, const pair<long long, long long>& B) {
		if (A.first == B.first) return A.second > B.second;
		return A.first > B.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case) {
		int N;
		cin >> N;

		vector<long long> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
		for (auto i : v) {
			pq.push({ 0, i });
		}

		long long sum = 0;
		while (pq.size() > 1) {
			auto a = pq.top(); pq.pop();
			auto b = pq.top(); pq.pop();

			sum += a.second + b.second;
			long long cnt = a.first <= b.first ? b.first : a.first;
			pq.push({ cnt, a.second + b.second });
		}
		cout << sum << '\n';
	}
}