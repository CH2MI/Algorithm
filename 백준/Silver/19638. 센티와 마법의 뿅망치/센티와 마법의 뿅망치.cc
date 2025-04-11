#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, H, T; cin >> N >> H >> T;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int h; cin >> h;
        pq.push(h);
    }

    int i;
    for (i = 0; i < T; i++) {
        int a = pq.top();
        if (a < H) break;
        pq.pop();
        if (a != 1) a /= 2;
        pq.push(a);
    }
    if (pq.top() < H) cout << "YES\n" << i;
    else cout << "NO\n" << pq.top();

}