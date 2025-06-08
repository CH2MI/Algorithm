#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K; cin >> N >> K;
    vector<int> v1(N), v2(N), v3(N);
    for (int& i : v1) cin >> i;
    for (int& i : v2) cin >> i;

    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pq.push({v1[i] * v2[j], j});
        }
    }

    for (int i = 0; i < K; i++) {
        auto [m, j] = pq.top();
        pq.pop();
        if (v3[j]) i--;
        else v3[j] = 1;
    }

    while (!pq.empty()) {
        auto [m, i] = pq.top();
        pq.pop();
        if (v3[i]) continue;
        cout << m;
        break;
    }
}