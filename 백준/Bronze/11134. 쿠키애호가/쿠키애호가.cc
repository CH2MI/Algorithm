#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n, c; cin >> n >> c;
        cout << (n - 1) / c + 1 << '\n';
    }
}