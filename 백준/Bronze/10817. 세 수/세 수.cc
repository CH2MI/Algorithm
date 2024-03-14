#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    int list[3];
    for (int i = 0; i < 3; ++i) {
        cin >> list[i];
    }
    
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (list[i] < list[j]) {
                int t = list[i];
                list[i] = list[j];
                list[j] = t;
            }  
        } 
    }
	
	cout << list[1];
}
