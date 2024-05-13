#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        int cnt = 0;
        int t = 0;
        string s; cin >> s;
        
        for (auto i : s) {
            if (i == 'X') t = 0;
            else t++;
            cnt += t;
        }
        
        cout << cnt << '\n';
    }
}