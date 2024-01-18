#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct coordinate {
	int A, B;
};

bool cmp(coordinate A, coordinate B) {
	return A.A < B.A;
}

int main() {
	int N;
	cin >> N;
	vector<coordinate> v;
	coordinate a;
	a.A = a.B = 0;
	v.push_back(a);
	for (int i = 0; i < N; i++) {
		coordinate t;
		cin >> t.A >> t.B;
		v.push_back(t);
	}

	sort(v.begin(), v.end(), cmp);

	int* dp = new int[N + 1]();
	int m = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (v[i].B > v[j].B) 
				if (dp[j] > cnt) cnt = dp[j];
		}
		dp[i] = cnt + 1;
		m = max(m, dp[i]);
	}
	cout << v.size() - m - 1;
}