#include <bits/stdc++.h>
using namespace std;

inline void judge(int score, array<int, 4>& g) {
    if (score >= 35 && score < 65) g[0]++;
    else if (score >= 65 && score < 95) g[1]++;
    else if (score >= 95 && score < 125) g[2]++;
    else if (score >= 125) g[3]++;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    array<int, 4> g{0};
    int time = 0, score = 0, ta = 4, sa = 1;;
    for (int& i : v) {
        if (time > 240) {
            judge(score, g);
            time = 0;
            score = 0;
            ta = 4;
            sa = 1;
        }
        if (i == 1) {
            judge(score, g);
            time = 0;
            score = 0;
            ta = 4;
            sa = 1;
            continue;
        }
        if (i == 2) {
            if (sa == 1) ta += 2;
            else sa /= 2;
        }
        else if (i == 4) time += 56;
        else if (i == 5) {
            if (ta > 1) --ta;
        }
        else if (i == 6) {
            if (sa < 32) sa *= 2;
        }
        time += ta;
        score += sa;
    }
    for (auto i : g) cout << i << '\n';
}