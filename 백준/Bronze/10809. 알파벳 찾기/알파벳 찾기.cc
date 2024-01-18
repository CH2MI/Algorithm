#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int a[26];
	cin >> s;

	for (int i = 0; i < 26; i++) {
		a[i] = -1;
	}

	for (int i = 0; i < s.size(); i++) {
		int t = (int)s[i] - 97;
		if (a[t] == -1) a[t] = i;
	} 
	
	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}
}