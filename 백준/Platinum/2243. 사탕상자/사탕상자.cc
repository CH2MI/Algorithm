#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 20;
int arr[sz << 1];

void update(int i, int value) {
    i += sz;
    while (i >= 1) {
        arr[i] += value;
        i >>= 1;
    }
}

int query(int x) {
    int i = 1, bias = 0;
    while (i < sz) {
        if (x <= arr[i << 1] + bias) i <<= 1;
        else bias += arr[i << 1], i = i << 1 | 1;
    }
    update(i - sz, -1);
    return i - sz;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    while (N--) {
        int A, B, C; cin >> A;
        if (A == 1) {
            cin >> B;
            cout << query(B) << '\n';
        }
        else {
            cin >> B >> C;
            update(B, C);
        }
    }
}