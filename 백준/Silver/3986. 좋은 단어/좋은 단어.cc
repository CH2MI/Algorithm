#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        stack<char> st;

        for (auto& c : s) {
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }

        ans += st.empty();
    }

    cout << ans;
}