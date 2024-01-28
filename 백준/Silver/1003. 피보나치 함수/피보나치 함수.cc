#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int t;
		cin >> t;
		vector<int> v0(t + 1, 0), v1(t + 1, 0);
		
		// 초기값을 넣는다.
		v0[0] = 1;
		if (t > 0) v1[1] = 1;
		
		// dp를 돌린다.
		for (int j = 2; j <= t; j++) {
			v0[j] = v0[j - 1] + v0[j - 2];
			v1[j] = v1[j - 1] + v1[j - 2];
		}
		cout << v0[t] << ' ' << v1[t] << '\n';
	}
}