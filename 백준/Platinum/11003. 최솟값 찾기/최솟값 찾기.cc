#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, L;
	cin >> N >> L;

	vector<int> v(N);
	deque<int> dq;

	for (int i = 0; i < N; i++) {
		cin >> v[i];

		while (!dq.empty() && v[dq.back()] >= v[i]) {
			dq.pop_back();
		}

		dq.push_back(i);

		if (dq.front() <= i - L) {
			dq.pop_front();
		}

		cout << v[dq.front()] << ' ';
	}
}