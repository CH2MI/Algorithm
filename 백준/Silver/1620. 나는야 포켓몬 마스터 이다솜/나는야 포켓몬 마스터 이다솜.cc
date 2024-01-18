#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N, M;
	cin >> N >> M;
	map<string, int> m;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v.push_back(s);
		m.insert(make_pair(s, i + 1));
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		try {
			int t = stoi(s);
			cout << v[t - 1] << '\n';
		}
		catch (exception& a) {
			cout << m[s] << '\n';
		}
	}
}