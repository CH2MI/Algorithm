#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		if (s.empty()) break;
		cout << s << endl;
	}
}