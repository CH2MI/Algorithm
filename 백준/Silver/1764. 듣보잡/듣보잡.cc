#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, string> m;
	vector<string> v;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		m.insert(make_pair(s, s));
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (m.count(s) == 1) v.push_back(s);
	}

	sort(v.begin(), v.end());
	int l = v.size();
	cout << l << '\n';
	for (int i = 0; i < l; i++)
		cout << v[i] << '\n';
}