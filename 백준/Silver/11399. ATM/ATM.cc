#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 정렬
	sort(v.begin(), v.end());

	// 누적 합을 구한다.
	vector<int> s(N + 1);
	s[0] = 0;
	for (int i = 0; i < N; i++) {
		s[i + 1] = v[i] + s[i];
	}

	// 누적 합을 모두 더한다.
	int sum = 0;
	for (auto& i : s) sum += i;
	cout << sum;
}