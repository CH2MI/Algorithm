#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<char> st;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        char n; cin >> n;
        st.insert(n);
    }
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        char m; cin >> m;
        st.insert(m);
    }
    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        char k; cin >> k;
        if (st.find(k) != st.end()) st.erase(k);
    }

    int S; string s;
    cin >> S;
    cin.ignore();
    getline(cin, s);
    st.insert(' ');
    bool f = 0;
    for (auto& c : s) {
        if (st.find(c) != st.end() && f) cout << '\n', f = 0;
        else if (st.find(c) == st.end()) cout << c, f = 1;
    }
}
