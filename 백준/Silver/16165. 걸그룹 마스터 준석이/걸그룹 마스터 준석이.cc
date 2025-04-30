#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    unordered_map<string, vector<string>> group;
    unordered_map<string, string> person;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        group.insert({s, vector<string>()});

        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            string t; cin >> t;
            group[s].push_back(t);
            person[t] = s;
        }
    }

    for (auto& [k, v] : group) {
        sort(v.begin(), v.end());
    }

    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        int q; cin >> q;
        if (q) {

            cout << person[s] << '\n';
        }
        else {
            for (auto& c : group[s]) cout << c << '\n';
        }
    }
}
