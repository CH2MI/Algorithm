#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> m;

bool incr(string a, string b) {
	if (m[a] == m[b] && a.size() == b.size()) return a < b;
	if (m[a] == m[b]) return a.size() > b.size();
	return m[a] > m[b];
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s.size() < M) continue;
		if (m.find(s) == m.end()) m.insert(make_pair(s, 1));
		else m[s]++;
	}
	for (auto iter : m) 
		v.push_back(iter.first);
	
	sort(v.begin(), v.end(), incr);

	for (auto iter : v)
		cout << iter << '\n';
} 