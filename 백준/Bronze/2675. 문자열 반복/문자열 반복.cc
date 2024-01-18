#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int T, R;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R;
		cin >> s;
		for (int j = 0; j < s.size(); j++) 
			for (int k = 0; k < R; k++) 
				cout << s[j];	
		cout << endl;
	}
}