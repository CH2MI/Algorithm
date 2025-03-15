#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v, d;

void rotate() {
    for (int i = N - 1; i > 0; i--) v[i] = v[i - 1];
    v.front() = v.back() = 0;

    int t = d.back();
    for (int i = 2 * N - 1; i > 0; i--) d[i] = d[i - 1];
    d.front() = t;
}

void move() {
    for (int i = N - 1; i > 0; i--) {
        if (!d[i] || v[i] || !v[i - 1]) continue;
        v[i] = v[i - 1];
        v[i - 1] = 0;
        --d[i];
    }
}



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> K;
    v.assign(N, 0);
    d.assign(N << 1, 0);
    for (int& i : d) cin >> i;

    int cnt = 1;
    while (1) {
        rotate();
        move();
        if (d.front()) {
            v.front() = 1;
            --d.front();
        }
        if (count(d.begin(), d.end(), 0) >= K) break;
        ++cnt;
    }
    cout << cnt;

}