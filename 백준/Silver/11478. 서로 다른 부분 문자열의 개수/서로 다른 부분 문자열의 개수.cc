#include <iostream>
#include <set>
using namespace std;

int main() {
	string s;
	set<string> S;
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l - i; j++) {
			string t = s.substr(j, i + 1);
			S.insert(t);
		}
	}
	cout << S.size();
}