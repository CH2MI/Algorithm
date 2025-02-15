#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int n = abs(N);
    string s;
    if (!n) {
        cout << 0;
        return 0;
    }
    while (n > 0) {
        if (n % 3 == 2) s += 'T', n++;
        else s += '0' + (n % 3), n -= (n % 3);
        n /= 3;
    }
    reverse(s.begin(), s.end());
    for (auto& c : s) {
        if (c == '1') cout << (N > 0 ? '1' : 'T');
        else if (c == 'T') cout << (N > 0 ? 'T' : '1');
        else cout << c;
    }
}