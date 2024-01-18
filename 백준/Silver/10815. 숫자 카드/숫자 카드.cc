#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	vector<int> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		if (binary_search(a.begin(), a.end(), t)) cout << "1 ";
		else cout << "0 ";
	}
}