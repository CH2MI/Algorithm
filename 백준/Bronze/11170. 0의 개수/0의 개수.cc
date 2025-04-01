#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int s, e; cin >> s >> e;
        int cnt = 0;
        for (int i = s; i <= e; i++) {
            string s = to_string(i);
            for (auto c : s) {
                if (c == '0') cnt++;
            }
        }
        cout << cnt << '\n';
    }
}