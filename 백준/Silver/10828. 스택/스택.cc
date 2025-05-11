#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    stack<int> st;

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        string q; cin >> q;
        if (q == "push") {
            int x; cin >> x;
            st.push(x);
        }
        else if (q == "pop") {
            if (st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n', st.pop();
        }
        else if (q == "size") cout << st.size() << '\n';
        else if (q == "empty") cout << st.empty() << '\n';
        else {
            if (st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }
}