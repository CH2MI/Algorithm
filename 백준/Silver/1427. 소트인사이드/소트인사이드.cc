#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	vector<int> a;
	int temp;
	cin >> s;

	for (int i = 0; i < s.size(); i++) a.push_back(s[i] - 48);

	sort(a.begin(), a.end(), greater<int>());

	for (int i = 0; i < a.size(); i++)
		cout << a[i];
}