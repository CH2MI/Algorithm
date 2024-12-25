#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 21;
int arr[sz << 1];

void update(int i, int mode) {
    i += sz;
    arr[i] += mode;
    while (i > 1) {
        i >>= 1;
        arr[i] += mode;
    }
}

int query(int x) {
    int i = 1;
    int bias = 0;
    while (i < sz) {
        if (x <= arr[i << 1] + bias) {
            i <<= 1;
        }
        else {
            bias += arr[i << 1];
            i = i << 1 | 1;
        }
    }
    update(i - sz, -1);
    return i - sz;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int q, t; cin >> q >> t;
        if (q == 1) {
            update(t, 1);
        }
        else cout << query(t) << '\n';
    } 
}