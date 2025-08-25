#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<string> v;

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string t;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] > '9') {
                if (!t.empty()) {
                    while (t.size() > 1 && t.front() == '0') t.erase(t.begin());
                    v.push_back(t);
                    t = string();
                }
            }
            else {
                t += s[i];
            }
        }
        if (!t.empty()) {
            while (t.size() > 1 && t.front() == '0') t.erase(t.begin());
            v.push_back(t);
        }
    }

    sort(v.begin(), v.end(),[] (auto& a, auto& b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    for (auto i : v) cout << i << '\n';

}