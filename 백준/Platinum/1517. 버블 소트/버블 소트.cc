#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 19;
array<int, 2> arr1[sz << 1];
long long arr2[sz << 1];

void update1(int i, int x) {
    i += sz;
    arr1[i] = {x, i - sz};
    while (i > 1) {
        i >>= 1;
        arr1[i] = max(arr1[i << 1], arr1[i << 1 | 1]);
    }
}

void update2(int i, long long x) {
    i += sz;
    arr2[i] += x;
    while (i > 1) {
        i >>= 1;
        arr2[i] = arr2[i << 1] + arr2[i << 1 | 1];
    }
}

array<int, 2> query1(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return {INT_MIN, -1};
    if (s <= ns && ne <= e) return arr1[node];
    int mid = ns + ne >> 1;
    return max(query1(s, e, node << 1, ns, mid), query1(s, e, node << 1 | 1, mid + 1, ne));
}

long long query2(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return 0;
    if (s <= ns && ne <= e) return arr2[node];

    int mid = ns + ne >> 1;
    return query2(s, e, node << 1, ns, mid) + query2(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        update1(i, a);
    }

    long long cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        auto q = query1(0, N - 1);
        cnt += N - i - 1 - (q[1] + query2(0, q[1]));
        update1(q[1], INT_MIN); update2(q[1], -1);
    }
    cout << cnt;
}