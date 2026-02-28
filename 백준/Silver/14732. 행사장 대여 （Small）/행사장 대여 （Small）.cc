#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int arr[501][501] = { 0 };

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                arr[x][y] = 1;
            }
        }
    }

    int cnt = 0;
    for (auto& i : arr) for (auto& j : i) cnt += j == 1;

    cout << cnt;

}
