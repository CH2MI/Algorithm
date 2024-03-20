#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    int arr[9] = { 0 };
    char c;
    
	while ((c = cin.get()) != '\n') {
	    int n = c - '0';
	    if (n == 9) n = 6;
	    ++arr[n];
	}
	
	int m = 0;
	for (int i = 0; i < 9; i++) {
	    if (i == 6) m = max(m, (arr[i] + 1) / 2);
	    else m = max(m, arr[i]); 
	}
    cout << m;
}
