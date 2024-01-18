#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	map<string, string> m;
	int N, M, c = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		m.insert(make_pair(s, s));
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (m.count(s) == 1) c++;
	}
	cout << c;
}