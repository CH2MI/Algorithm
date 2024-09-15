#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

int DFS(int l, int r) {
	if (l >= r) {
		return 0;
	}

	int count = 0;
	if (v[l] + v[r] == M) {
		count = DFS(l + 1, r - 1) + 1;
	}
	else if (v[l] + v[r] > M) {
		count = DFS(l, r - 1);
	}
	else {
		count = DFS(l + 1, r);
	}
	return count;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	
	cin >> N >> M;
	
	v.assign(N, 0);

	for (auto& i : v) cin >> i;

	sort(v.begin(), v.end());

	cout << DFS(0, N - 1);
}