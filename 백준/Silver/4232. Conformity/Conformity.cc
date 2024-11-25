#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int n; cin >> n;
        if (!n) break;

        map<vector<int>, int> m;
        for (int i = 0; i < n; i++) {
            vector<int> v(5);
            for (auto& j : v) cin >> j;
            sort(v.begin(), v.end());
            m[v]++;
        }

        int mx = 0, cnt = 0;
        for (auto& i : m) {
            if (mx == i.second) cnt += i.second;
            else if (mx < i.second) cnt = i.second, mx = i.second;
        }
        cout << cnt << '\n';
    }
}