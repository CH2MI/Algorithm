#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;
    stack<array<int, 2>> st;

    int sum = 0;
    char repeat = ' ';
    for (auto c : s) {
        if (c == '(') {
            st.push({sum, repeat});
            sum = 0, repeat = ' ';
        }
        else if (c == ')') {
            if (repeat != ' ') sum += 1, repeat = ' ';
            auto [s, r] = st.top();
            st.pop();
            sum = sum * ((char)r - '0') + s;
        }
        else {
            if (repeat != ' ') sum += 1;
            repeat = c;
        }
    }
    if (repeat != ' ') sum += 1;
    cout << sum;
}