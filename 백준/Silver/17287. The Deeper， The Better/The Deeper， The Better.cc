#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int mx = 0, sum = 0;;
    for (auto& c : s) {
        if (c == '(') sum += 1;
        else if (c == '{') sum += 2;
        else if (c == '[') sum += 3;
        else if (c == ')') sum -= 1;
        else if (c == '}') sum -= 2;
        else if (c == ']') sum -= 3;
        else mx = max(mx, sum);
    }
    cout << mx;
}