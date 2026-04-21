#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    unordered_set<string> st;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;

        if (s.size() >= 6 && s.substr(s.size() - 6) == "Cheese") st.insert(s);
    }

    if (st.size() >= 4) cout << "yummy";
    else cout << "sad";
}
