#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int i;
	getline(cin, s);
	cin >> i;
	cout << s[i - 1];
}