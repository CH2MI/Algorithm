#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; getline(cin, s);

    set<string> st;
    while (1) {
        string s1; getline(cin, s1);
        if (s1 == "what does the fox say?") break;

        string tmp;
        for (auto c : s1) {
            if (c == ' ') tmp = "";
            else tmp += c;
        }
        st.insert(tmp);
    }

    string tmp;
    for (auto c : s) {
        if (c == ' ') {
            if (st.find(tmp) == st.end()) cout << tmp << ' ';
            tmp = "";
        }
        else {
            tmp += c;
        }
    }

    if (st.find(tmp) == st.end()) cout << tmp;
    cout << '\n';

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T; cin.ignore();
    while (T--) {
        solve();
    }
}
