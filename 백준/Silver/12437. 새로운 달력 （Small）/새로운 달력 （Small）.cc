#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int i = 1 ; i <= T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int cnt = 0, nxt = b;
        for (int i = 0; i < a; i++) {
            cnt += nxt / c;
            if (nxt % c) {
                cnt++;
                nxt = b + nxt % c;
            }
        }
        cout << "Case #" << i << ": " << cnt << '\n';
    }
}