#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int count = 0, l = s.size();
	for (int i = 0; i < l; i++) {
		count++;

		if (s[i] == 'c' && i < l - 1) 
			if (s[i + 1] == '=' || s[i + 1] == '-') 
				i++;
		
		if (s[i] == 'd' && i < l - 2) 
			if (s[i + 1] == 'z' && s[i + 2] == '=') 
				i += 2;
		
		if (s[i] == 'd' && i < l - 1) 
			if (s[i + 1] == '-')
				i++;

		if (s[i] == 'l' && i < l - 1) 
			if (s[i + 1] == 'j') 
				i++;
		
		if (s[i] == 'n' && i < l - 1) 
			if (s[i + 1] == 'j') 
				i++;
		
		if (s[i] == 's' && i < l - 1) 
			if (s[i + 1] == '=') 
				i++;
		
		if (s[i] == 'z' && i < l - 1) 
			if (s[i + 1] == '=') 
				i++;
		
	}
	cout << count;
}