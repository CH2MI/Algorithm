#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    deque<int> d(N);
    for (int i = 1; i <= N; i++) d[i - 1] = i;

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        int m; cin >> m;
        int p = find(d.begin(), d.end(), m) - d.begin();
        if (p <= d.size() / 2) {
            for (int j = 0; j < p; j++) {
                d.push_back(d.front());
                d.pop_front();
                ++cnt;
            }
            d.pop_front();
        }
        else {
            for (int j = 0; j < d.size() - p; j++) {
                d.push_front(d.back());
                d.pop_back();
                ++cnt;
            }
            d.pop_front();
        }
    }
    cout << cnt;
}