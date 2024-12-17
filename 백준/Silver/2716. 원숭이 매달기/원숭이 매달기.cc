#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T; cin.ignore();
    while (T--) {
        string s; getline(cin, s);
        stack<char> st;
        long long d = 0;
        for (auto c : s) {
            if (c == '[') st.push(c);
            else {
                d = max(d, (long long)st.size());
                st.pop();
            }
        }
        cout << (1ll << d) << '\n';
    }
}