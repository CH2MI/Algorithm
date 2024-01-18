#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	map<int, int> m;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (m.count(t) == 0)
			m.insert(make_pair(t, 1));
		else m[t]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		if (m.count(t) == 0)
			cout << "0 ";
		else cout << m[t] << ' ';
	}
}