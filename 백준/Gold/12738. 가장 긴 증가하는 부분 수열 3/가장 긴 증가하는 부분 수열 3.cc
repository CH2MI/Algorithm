#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	int* arr = new int[N + 1]();
	int* dp = new int[N + 1]();
	vector<int> v; v.push_back(-1000000001);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[0] = -1000000001;
	int m = 0;
	int t = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		int j;
		int t;
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			t = v.size() - 1;
		}
		else {
			t = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			if (v[t] > arr[i]) v[t] = arr[i];
		}
		dp[i] = t; 
		m = max(t, m);
	}
	cout << m;
}
