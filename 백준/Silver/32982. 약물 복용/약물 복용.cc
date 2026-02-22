#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, K; cin >> N >> K;
    array<array<int, 2>, 3> arr{};
    for (auto& i : arr) for (int& j : i) cin >> j;

    int eat_time = arr[0][1];

    int day;
    for (day = 1; day <= N; day++) {
        if (eat_time + K < arr[1][0]) break;
        eat_time = min(eat_time + K, arr[1][1]);

        if (eat_time + K < arr[2][0]) break;
        eat_time = min(eat_time + K, arr[2][1]);

        if (day == N) continue;
        
        if (eat_time + K < arr[0][0] + 1440) break;
        eat_time = min((eat_time + K) % 1440, arr[0][1]);
    }

    if (day == N + 1) cout << "YES";
    else cout << "NO";
}
