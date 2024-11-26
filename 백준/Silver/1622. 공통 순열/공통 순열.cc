#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        map<char, int> m;
        for (auto c : a) m[c]++;
        vector<char> v;
        for (auto c : b) {
            if (m[c]) v.push_back(c), m[c]--;
        }
        sort(v.begin(), v.end());
        for (auto c : v) cout << c;
        cout << '\n';
    }
}