#include <bits/stdc++.h>
using namespace std;

int v[5][5];
vector<array<int, 2>> arr;

bool ispossible() {
    vector<bool> visited(7);
    queue<int> q;
    q.push(0);
    int cnt = 0;
    while (!q.empty()) {
        int k = q.front(); q.pop();
        if (visited[k]) continue;
        visited[k] = 1;
        ++cnt;
        for (int i = 0; i < 7; i++) {
            if (visited[i]) continue;
            if (abs(arr[k][0] - arr[i][0]) + abs(arr[k][1] - arr[i][1]) == 1) q.push(i);
        }
    }
    return cnt == 7;
}

int BT(int n, int index) {
    arr.push_back({index / 5, index % 5});
    if (n == 6) {
        if (!ispossible()) {
            arr.pop_back();
            return 0;
        }
        array<int, 2> a({0, 0});
        for (auto& [r, c] : arr) a[v[r][c]]++;
        arr.pop_back();
        if (a[0] < a[1]) return 0;
        return 1;
    }

    int cnt = 0;
    for (int i = index + 1; i < 25; i++) {
        cnt += BT(n + 1, i);
    }
    arr.pop_back();
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (auto& i : v) {
        string s; cin >> s;
        for (int j = 0; j < 5; j++) {
            if (s[j] == 'Y') i[j] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 25; i++) {
        cnt += BT(0, i);
    }
    cout << cnt;

}
