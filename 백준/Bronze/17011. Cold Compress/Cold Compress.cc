#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        
        char t = s[0]; 
        int cnt = 0;
        for (auto i : s) {
            if (t == i) cnt++;
            else {
                cout << cnt << ' ' << t << ' ';
                t = i;
                cnt = 1;
            }
        }
        cout << cnt << ' ' << t << '\n';
    }
}