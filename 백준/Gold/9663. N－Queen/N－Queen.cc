#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int isPossible(int r, int c) {

    // 열 검사
    for (int i = 0; i < r; i++) {
        if (v[i] == c) return 0;
    }

    // 대각선 검사
    for (int i = 0; i < r; i++) {
        int dr = abs(i - r);
        int dc = abs(v[i] - c);

        if (dr == dc) return 0;
    }

    return 1;
}

int go(int cur) {
    if (cur == N) return 1;

    int cnt = 0;

        for (int i = 0; i < N; i++) {
            if (isPossible(cur, i)) {
                v[cur] = i;
                cnt += go(cur + 1);
                v[cur] = -1;
            }
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    v.assign(N, -1);

    cout << go(0);
}