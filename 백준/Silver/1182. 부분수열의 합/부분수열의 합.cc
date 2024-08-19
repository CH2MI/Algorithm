#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> v;

int DFS(int target, int count, int sum, int index) {
	if (count == target) {
		if (sum == S) return 1;
		else return 0;
	}

	int cnt = 0;
	for (int i = index; i < N; i++) {
		cnt += DFS(target, count + 1, sum + v[i], i + 1);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> S;
	v = vector<int>(N);

	for (auto& i : v)
		cin >> i;

	int count = 0;
	for (int i = 1; i <= N; i++) {
		count += DFS(i, 0, 0, 0);
	}
	cout << count;
}