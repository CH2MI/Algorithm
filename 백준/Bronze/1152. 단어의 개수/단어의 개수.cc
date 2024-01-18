#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int i = 0, count = 0, t = s.size();
	if (s[0] == ' ') i++;
	for (; i < t; i++) {
		if (s[i] == ' ') count++;
	}
	if (s[t - 1] != ' ') count++;
	cout << count;
}