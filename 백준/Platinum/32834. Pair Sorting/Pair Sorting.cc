#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N; cin >> N;
    vector<array<int, 2>> v1, v2;
    for (int i = 0; i < N; i++) {
        v1.push_back({N - i, N - i});
        v2.push_back({i + 1, i + 1});
    }

    vector<array<int, 3>> ans;

    while (v1 != v2) {
        int i = 0, a = 0, ah = 0;

        for (int j = 0; j < N; j++) {
            if (v1[j][0] != j + 1) {
                if (a < v1[j][0]) i = j, a = v1[j][0], ah = 0;
            }
            if (v1[j][1] != j + 1) {
                if (a < v1[j][1]) i = j, a = v1[j][1], ah = 1;
            }
        }

        for (int j = i + 1; j < N; j++) {
            i = j - 1;
            int b = 0, bh = 0;
            if (v1[j][0] > v1[j][1]) b = v1[j][1], bh = 1;
            else b = v1[j][0], bh = 0;
            if (i == a - 1) break;
            ans.push_back({i + 1, a, b});
            swap(v1[i][ah], v1[j][bh]);
            ah = bh;

        }
    }
    cout << ans.size() << '\n';
    for (auto& [a, b, c] : ans) cout << a << ' ' << b << ' ' << c << '\n';
}