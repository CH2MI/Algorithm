#include <bits/stdc++.h>
using namespace std;

constexpr int maxlen = 19;

int N;
vector<vector<int>> table;

void make_table() {
    for (int i = 1; i < maxlen; i++) {
        for (int j = 1; j <= N; j++) {
            table[j][i] = table[table[j][i - 1]][i - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    table.assign(N + 1, vector<int>(maxlen));

    for (int i = 1; i <= N; i++) cin >> table[i][0];
    make_table();

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int n, x; cin >> n >> x;
        for (int j = 0; j < maxlen; j++) {
            if (n & (1 << j)) x = table[x][j];
        }
        cout << x << '\n';
    }
}
