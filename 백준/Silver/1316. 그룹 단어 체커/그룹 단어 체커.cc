#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, count = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		int a[26] = { 0, };
		int j;
		cin >> s;
		for (j = 0; j < s.size(); j++) {
			int t = s[j] - 97;
			if (a[t] == 0) 
				a[t] = 1;
			else if (a[t] == 1 && s[j - 1] - 97 == t) continue;
			else break;
		}
		if (j == s.size()) count++;
	}
	cout << count;
}