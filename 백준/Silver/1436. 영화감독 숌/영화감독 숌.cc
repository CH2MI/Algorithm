#include <iostream>
#include <string>
using namespace std;

int main() {
	int count = 1, N;
	cin >> N;
	int i = 666;
	while (count < N) {
		string s = to_string(++i);
		if (s.find("666") != string::npos) count++;
	}
	cout << i;
}