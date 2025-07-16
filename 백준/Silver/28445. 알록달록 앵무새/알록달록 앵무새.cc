#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> v(4);
    for (auto& s : v) cin >> s;
    set<string> set;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            set.insert(v[i] + " " + v[j]);
        }
    }
    for (auto& s : set) cout << s << '\n';
}