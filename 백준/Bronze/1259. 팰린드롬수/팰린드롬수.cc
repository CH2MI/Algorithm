#include <iostream>
using namespace std;

bool is_Palindrome(const string& s, int Size) {
    for (int i = 0; i < Size / 2; i++) {
        if (s[i] != s[Size - i - 1]) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true) {
	    string s;
	    cin >> s;
	    if (s == "0") break;
	    
	    if (is_Palindrome(s, s.size())) cout << "yes\n";
	    else cout << "no\n";
	}
}
