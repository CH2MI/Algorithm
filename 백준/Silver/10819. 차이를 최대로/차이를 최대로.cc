#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v, ans, visited;

int go(int cnt) {
    if (cnt == 0) {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += abs(ans[i] - ans[i + 1]);
        }
        return sum;
    }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        visited[i] = 1;
        ans.push_back(v[i]);
        ret = max(ret, go(cnt - 1));
        ans.pop_back();
        visited[i] = 0;
    }

    return ret;
}



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;
    v.assign(N, 0);
    visited.assign(N, 0);
    for (int& i : v) cin >> i;

    cout << go(N);

}
