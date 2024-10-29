#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (!N && !M) break;

        unordered_map<int, int> map;
        for (int i = 0; i < N; i++) {
            int n; cin >> n;
            map[n] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < M; i++) {
            int m; cin >> m;
            auto itr = map.find(m);
            if (itr != map.end()) cnt++;
        }

        cout << cnt << '\n';
    }
}