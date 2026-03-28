#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    unordered_set<string> st;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        st.insert(s);
    }

    for (auto& s : st) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        if (st.find(tmp) != st.end()) {
            cout << s.size() << ' ' << s[s.size()/ 2];
            break;
        }
    }
}
