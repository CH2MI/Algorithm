#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K, M; cin >> N >> K >> M;

    deque<int> dq(N);
    iota(dq.begin(), dq.end(), 1);

    int d = 1;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (d == 1) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        if (d == 1) {
            cout << dq.back() << '\n';
            dq.pop_back();
        }
        else {
            cout << dq.front() << '\n';
            dq.pop_front();
        }
        if (++cnt == M) {
            cnt = 0;
            d = -d;
        }
    }
}
