#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> v;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int search() {
    int mx = 0;
    for (int i = 0; i < N; i++) {
        int rcnt = 1, ccnt = 1;
        for (int j = 1; j < N; j++) {
            if (v[i][j - 1] == v[i][j]) mx = max(mx, ++ccnt);
            else ccnt = 1;
            if (v[j - 1][i] == v[j][i]) mx = max(mx, ++rcnt);
            else rcnt = 1;
        }
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    v.assign(N, string());
    for (auto& s : v) cin >> s;

    int mx = search();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int r = i + dr[k];
                int c = j + dc[k];
                if (r < 0 || r >= N || c < 0 || c >= N) continue;
                swap(v[i][j], v[r][c]);
                mx = max(mx, search());
                swap(v[i][j], v[r][c]);
            }
        }
    }
    cout << mx;
}