#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 17;
long long arr[sz << 1];

void update(int i, long long x) {
    i += sz;
    arr[i] = x;

    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

long long query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = (ns + ne) / 2;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        update(i, a);
    }

    int M; cin >> M;
    vector<array<int, 2>> q1; q1.reserve(M);
    vector<array<int, 4>> q2; q2.reserve(M);

    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        if (q == 1) {
            int a, b; cin >> a >> b;
            q1.push_back({a - 1, b});
        }
        else {
            int a, b, c; cin >> a >> b >> c;
            q2.push_back({a, b - 1, c - 1, (int)q2.size()});
        }
    }
    sort(q2.begin(), q2.end());
    vector<long long> ans(q2.size());

    int idx = 0;
    for (auto& q : q2) {
        while (idx < q[0]) {
            update(q1[idx][0], q1[idx][1]);
            idx++;
        }

        ans[q[3]] = query(q[1], q[2]);
    }
    for (auto i : ans) cout << i << '\n';
}