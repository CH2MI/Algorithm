#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (true) {
	    string s;
	    getline(cin, s);
	    
	    if (s == "END") break;
	    
	    for (auto itr = s.rbegin(); itr != s.rend(); itr++) {
	        cout << *itr;
	    }
	    cout << '\n';
	}
}
