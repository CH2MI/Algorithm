#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> value(N);
	for (int i = 0; i < N; i++)
		cin >> value[i];
	int count = 0;
	int T = K;
	while (T > 0) {
		// 이진 탐색으로 큰 값중 가장 작은 값을 찾는다.
		auto i = upper_bound(value.begin(), value.end(), T);
        // 그 전 값으로 계산한다
		int t = T / *--i;
		count += t;
		T -= t * *i;
	}
	cout << count;
}