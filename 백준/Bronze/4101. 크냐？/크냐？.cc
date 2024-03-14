#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
	    int A, B;
	    cin >> A >> B;
	    if (!A && !B) break;
	    
	    if (A <= B) cout << "No\n";
	    else cout << "Yes\n";
	}
}
