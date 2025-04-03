#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = 0; k < N; k++) {
                if (i == k || j == k) continue;
                if ((v[i] - v[j]) % v[k]) return 0;
            }
        }
    }
    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    v.assign(N, 0);
    for (int& i : v) cin >> i;
    if (solve()) cout << "yes";
    else cout << "no";
}