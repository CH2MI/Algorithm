#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	set<string> us;
	int count = 0;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s == "ENTER") us.clear();
		else {
			auto itr = us.find(s);
			if (itr == us.end()) {
				us.insert(s);
				count++;
			}
		}
	}
	cout << count;
}