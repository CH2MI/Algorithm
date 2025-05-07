#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int H, W; cin >> H >> W;

    for (int i = 0; i < H; i++) {
        string s; cin >> s;
        int cnt = -1;

        for (auto& c : s) {
            if (c == '.' && cnt == -1) cout << cnt << ' ';
            else if (c == '.' && cnt != -1) cout << ++cnt << ' ';
            else cout << (cnt = 0) << ' ';
        }
        cout << '\n';
    }

}