#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	cin >> v[0];
	for (int i = 1; i < N; i++) {
		cin >> v[i];
	}

	vector<int> sum;
	sum.push_back(0);
	for (int i = 0; i < N; i++) {
		sum.push_back(sum[i] + v[i]);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		cout << sum[b] - sum[a] << '\n';
	}
}
