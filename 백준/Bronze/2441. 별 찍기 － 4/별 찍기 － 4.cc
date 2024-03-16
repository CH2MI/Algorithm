#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (; j < i; j++) {
            cout << ' ';
        }
        for (; j < N; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}