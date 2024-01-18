#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool incr(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<string> a;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		a.push_back(s);
	}
	sort(a.begin(), a.end(), incr);
	a.erase(unique(a.begin(), a.end()), a.end());

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << '\n';
}