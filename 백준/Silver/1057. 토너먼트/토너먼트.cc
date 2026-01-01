#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N, a, b; cin >> N >> a >> b;

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (i == a) q.push(1);
        else if (i == b) q.push(2);
        else q.push(0);
    }

    int cnt = 1;
    while (q.size() > 1) {
        queue<int> tq;
        int l = q.size();
        for (int i = 0; i < l / 2; i++) {
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();

            if (x == 1 && y == 2 || x == 2 && y == 1) {
                cout << cnt;
                return 0;
            }

            if (x == 1 || x == 2) tq.push(x);
            else if (y == 1 || y == 2) tq.push(y);
            else tq.push(0);
        }

        if (!q.empty()) tq.push(q.front());

        q = move(tq);
        cnt++;
    }

}
