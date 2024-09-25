#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	long long T;
	cin >> N >> K >> T;

	vector<long long> v(N);
	for (auto& i : v) cin >> i;
	sort(v.begin(), v.end());

	stack<long long> s;
	for (int i = 0; i < N; i++) {
		if (K == 0) break;
		if (v[i] < T) {
			s.push(v[i]);
		}
		else {
			if (s.empty()) break;
			T += s.top();
			s.pop();
			i--;
			K--;
		}
	}

	while (!s.empty() && K) {
		T += s.top();
		s.pop();
		K--;
	}
	cout << T;
}