#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    if (N == 1 && M == 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    vector<array<int, 2>> ans;
    ans.reserve(3 * M);

    for (int i = 0; i < 3 * N; i++) {
        ans.push_back({i, (i + 1) % (3 * N)});
    }

    int step = 0, i = 0;
    while ((int)ans.size() < 3 * M) {
        if (i == N - 1) {
            ans.push_back({i * 3, (i - 1) * 3});
            ans.push_back({(i - 1) * 3, (i - 1) * 3 + 2});
            ans.push_back({(i - 1) * 3 + 2, i * 3 + 2});
        }
        else if (!step) {
            ans.push_back({i * 3, (i + 1) * 3});
            ans.push_back({i * 3 + 1, (i + 1) * 3 + 1});
            ans.push_back({i * 3 + 2, (i + 1) * 3 + 2});
            step ^= 1;
        }
        else {
            ans.push_back({i * 3, i * 3 + 2});
            ans.push_back({i * 3, (i + 1) * 3 + 1});
            ans.push_back({i * 3 + 2, (i + 1) * 3 + 1});
            step ^= 1;
            i += 2;
        }

    }
    for (auto&[s, e] : ans) cout << s + 1 << ' ' << e + 1 << '\n';

}