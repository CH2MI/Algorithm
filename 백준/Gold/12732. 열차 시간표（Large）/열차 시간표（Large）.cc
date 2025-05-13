#include <bits/stdc++.h>
using namespace std;

void Solve(int c) {
    int T; cin >> T;

    int A, B; cin >> A >> B;

    vector<array<int, 2>> v;
    v.reserve((A + B) * 2);

    for (int i = 0; i < A; i++) {
        string sa, sb; cin >> sa >> sb;
        int a = stoi(sa.substr(0, 2)) * 60 + stoi(sa.substr(3));
        int b = stoi(sb.substr(0, 2)) * 60 + stoi(sb.substr(3));
        v.push_back({a, 1}); v.push_back({b + T, -2});
    }
    for (int i = 0; i < B; i++) {
        string sa, sb; cin >> sa >> sb;
        int a = stoi(sa.substr(0, 2)) * 60 + stoi(sa.substr(3));
        int b = stoi(sb.substr(0, 2)) * 60 + stoi(sb.substr(3));
        v.push_back({a, 2}); v.push_back({b + T, -1});
    }
    sort(v.begin(), v.end());

    array<int, 2> ans{0, 0}, t{0, 0};
    for (auto [x, y] : v) {
        if (y > 0) {
            if (!t[y - 1]) ++ans[y - 1];
            else --t[y - 1];
        }
        else t[-y - 1]++;
    }

    cout << "Case #" << c << ": " <<  ans[0] << ' ' << ans[1] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        Solve(i + 1);
    }
}