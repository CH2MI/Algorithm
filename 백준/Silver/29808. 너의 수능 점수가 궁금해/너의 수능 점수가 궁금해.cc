#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<array<int, 2>> ans;

    if (!(N % 4763)) {
        int sum = N / 4763;

        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                if (i * 508 + j * 212 == sum) ans.push_back({i, j});
                else if (i * 508 + j * 305 == sum) ans.push_back({i, j});
                else if (i * 108 + j * 212 == sum) ans.push_back({i, j});
                else if (i * 108 + j * 305 == sum) ans.push_back({i, j});
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
}