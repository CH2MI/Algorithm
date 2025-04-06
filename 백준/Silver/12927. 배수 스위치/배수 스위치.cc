#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;
    int cnt = 0;
    for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] == 'N') continue;
        cnt++;
        for (int j = i + i; j <= s.size(); j += i) {
            if (s[j - 1] == 'Y') s[j - 1] = 'N';
            else s[j - 1] = 'Y';
        }
    }
    cout << cnt;

}