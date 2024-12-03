#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<array<int, 2>> v;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s == "order") {
            int t, n; cin >> n >> t;
            v.push_back({t, n});
        }
        else if (s == "sort") {
            sort(v.begin(), v.end());
        }
        else {
            int n; cin >> n;
            for (int i = 0; i < N; i++) {
                if (v[i][1] == n) {
                    v.erase(v.begin() + i);
                    break;
                }
            }
        }

        if (v.empty()) cout << "sleep";
        else for (auto i : v) cout << i[1] << ' ';
        cout << '\n';
    }
}
