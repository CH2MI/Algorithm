#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	map<char, int> m;
	string S; cin >> S;
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		if (S.find(s[0]) != string::npos) {
			m[s[0]]++;
		}
	}

	long long ret = 1;
	for (auto& c : S) {
		auto itr = m.find(c);
		if (itr == m.end()) ret = 0;
		else {
			ret *= itr->second;
			--itr->second;
			}
		}

	if (S[0] == S[1] && S[1] == S[2]) ret /= 6;
	else if (S[0] == S[1] || S[0] == S[2] || S[1] == S[2]) ret /= 2;
	cout << ret;
}