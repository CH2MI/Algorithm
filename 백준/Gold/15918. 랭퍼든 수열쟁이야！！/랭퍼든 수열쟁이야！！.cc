#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v, selected;

int go(int cur) {
    if (cur == N) return 1;

    int ret = 0;
    if (selected[cur]) {
        ret = go(cur + 1);
    }
    else {
        for (int i = 0; i < N * 2 - (cur + 2); i++) {
            if (v[i] || v[i + cur + 2]) continue;
            v[i] = v[i + cur + 2] = cur + 1;
            selected[cur] = 1;
            ret += go(cur + 1);
            selected[cur] = 0;
            v[i] = v[i + cur + 2] = 0;
        }
    }
    return ret;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int x, y; cin >> N >> x >> y;
    selected.assign(N, 0);
    v.assign(N << 1, 0);
    int fixed = y - x - 1;
    v[x - 1] = v[y - 1] = fixed;
    selected[fixed - 1] = 1;

    cout << go(0);
}