#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> q;
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) q.push(i);

    cout << '<';
    for (; !q.empty(); q.pop()) {
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if (q.size() > 1) cout << ", ";
    }
    cout << '>';
}