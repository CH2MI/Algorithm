#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
vector<int> arr[sz << 1];

void merge(int node) {
    int left = node << 1, right = node << 1 | 1;
    int i = 0, l = 0, r = 0, L = (int)arr[left].size(), R = (int)arr[right].size();
    arr[node] = vector<int>(L + R);

    while (l < L && r < R) {
        if (arr[left][l] < arr[right][r]) arr[node][i++] = arr[left][l++];
        else arr[node][i++] = arr[right][r++];
    }

    while (l < L) arr[node][i++] = arr[left][l++];
    while (r < R) arr[node][i++] = arr[right][r++];

}

void init(int node = 1, int ns = 0, int ne = sz - 1) {
    if (ns == ne) return;

    int mid = (ns + ne) / 2;
    init(node << 1, ns, mid);
    init(node << 1 | 1, mid + 1, ne);
    merge(node);
}

int query(int s, int e, int q, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return 0;
    if (s <= ns && ne <= e) {
        return (int)arr[node].size() - (upper_bound(arr[node].begin(), arr[node].end(), q) - arr[node].begin());
    }

    int mid = (ns + ne) / 2;
    return query(s, e, q, node << 1, ns, mid) + query(s, e, q, node << 1 | 1, mid + 1, ne);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        arr[i + sz] = { a };
    }

    init();

    int last_ans = 0;
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a ^= last_ans; b ^= last_ans; c ^= last_ans;
        last_ans = query(a - 1, b - 1, c);
        cout << last_ans << '\n';
    }
}