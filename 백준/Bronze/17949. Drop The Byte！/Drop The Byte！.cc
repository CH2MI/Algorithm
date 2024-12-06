#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n, index = 0;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        int len = 2;
        if (a == "int") {
            len = 8;
        }
        else if (a == "long_long") {
            len = 16;
        }
        string t = s.substr(index, len);
        cout << stoll(t, nullptr, 16) << ' ';
        index += len;
    }
}
