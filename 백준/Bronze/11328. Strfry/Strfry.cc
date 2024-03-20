#include <iostream>
using namespace std;

bool is_possible(int arr[]) {
    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0) return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
	    string a, b;
	    cin >> a >> b;
	    int arr[26] = { 0 };
	    int k = a.size();
	    int l = b.size();
	    
	    for (int i = 0; i < k; i++) {
	        arr[a[i] - 'a']++;
	    }
	    
	    for (int i = 0; i < l; i++) {
	        arr[b[i] - 'a']--;
	    }
	    
	    if (is_possible(arr)) cout << "Possible\n";
	    else cout << "Impossible\n";
	}
}
