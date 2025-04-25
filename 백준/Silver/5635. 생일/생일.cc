#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<tuple<int, int, int, string>> v(N);

    for (int i = 0; i < N; i++) {
        string s; int d, m, y;
        cin >> s >> d >> m >> y;
        v[i] = {y, m, d, s};
    }

    sort(v.begin(), v.end());
    cout << get<3>(v.back()) << '\n' << get<3>(v.front());
}