#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	set<string> dance, rainbowdance;
	rainbowdance.insert("ChongChong");
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (!rainbowdance.count(s1) && !rainbowdance.count(s2)) {
			dance.insert(s1);
			dance.insert(s2);
		}
		else {
			rainbowdance.insert(s1);
			rainbowdance.insert(s2);
		}
	}
	cout << rainbowdance.size();
}