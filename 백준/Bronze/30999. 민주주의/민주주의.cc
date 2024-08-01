#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int cnt = 0;
    while (N--) {
        string s;
        cin >> s;
        
        int count = 0;
        for (const auto& i : s) {
            if (i == 'O') count++;
        }
        
        if (M - count < count) cnt++;
    }
    
    cout << cnt;
}