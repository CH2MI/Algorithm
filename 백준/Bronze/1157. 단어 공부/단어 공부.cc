#include <iostream>
#include <string>
using namespace std;

int main() {
	int a[26] = { 0, };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int t = s[i];
		if (t > 90) t -= 97;
		else t -= 65;
		a[t]++;
	}
	
	int index, max = 0, count = 0;
	for (int i = 0; i < 26; i++) {
		if (max < a[i]) {
			max = a[i];
			count = 1;
			index = i;
		}
		else if (max == a[i] && max != 0) 
			count++;
	}
	if (count > 1) index = -2;
	cout << (char)(index + 65);
}