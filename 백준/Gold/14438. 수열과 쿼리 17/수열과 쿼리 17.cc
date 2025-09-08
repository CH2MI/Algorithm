#include <bits/stdc++.h>
using namespace std;

int N, r, g;
vector<int> arr, groups;

void init() {
    r = sqrt(N), g = ceil((double)N / r);
    groups.assign(g, 0);

    for (int i = 0; i < g; i++) {
        groups[i] = *min_element(arr.begin() + i * r, min(arr.begin() + (i + 1) * r, arr.end()));
    }
}

void update(int i, int x) {
    arr[i] = x;

    int gi = i / r;
    groups[gi] = *min_element(arr.begin() + gi * r, min(arr.begin() + (gi + 1) * r, arr.end()));
}

int query(int s, int e) {
    int gs = s / r, ge = e / r;

    if (gs == ge) {
        return *min_element(arr.begin() + s, arr.begin() + e + 1);
    }

    int left = *min_element(arr.begin() + s, min(arr.begin() + (gs + 1) * r, arr.end()));
    int right = *min_element(arr.begin() + ge * r, arr.begin() + e + 1);
    int mid = INT_MAX;
    if (gs + 1 < ge) mid = *min_element(groups.begin() + gs + 1, groups.begin() + ge);

    return min({left, mid, right});
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N;
    arr.assign(N, 0);

    for (int& i : arr) cin >> i;
    init();

    int M; cin >> M;

    for (int i = 0; i < M; i++) {
        int q, a, b; cin >> q >> a >> b;
        if (q == 1) {
            update(a - 1, b);
        }
        else {
            cout << query(a - 1, b - 1) << '\n';
        }
    }
}
