#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;

    stack<char> st;
    bool is_stack = false;
    for (auto c : s) {
        if (!is_stack) {
            if (c == '(') is_stack = true;
            else cout << c;
        }
        else {
            if (c == ')') {
                is_stack = false;
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
            }
            else st.push(c);
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}