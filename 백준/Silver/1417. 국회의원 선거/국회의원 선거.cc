#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    priority_queue<int> pq;
    int N; cin >> N;

    int d; cin >> d;
    for (int i = 1; i < N; i++) {
        int a; cin >> a;

        pq.push(a);
    }

    int cnt = 0;
    while (!pq.empty() && pq.top() >= d) {
        auto a = pq.top(); pq.pop();
        --a; ++d; ++cnt;
        pq.push(a);
    }

    cout << cnt;

}
