#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    unordered_map<string, int> m;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string s; char c;
        cin >> s >> c;

        if (c == '+') m[s]++;
        else {
            auto itr = m.find(s);
            if (itr == m.end()) cnt++;
            else {
                if (--(itr->second) == 0) m.erase(itr);
            }
        }
    }

    for (auto& itr : m) {
        cnt += itr.second;
    }

    cout << cnt;

}