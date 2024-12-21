#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll, 2> point;
vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int CCW(point& a, point& b, point& c) {
    ll ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

bool intersect(point& a, point& b, point& c, point& d) {
    int abc = CCW(a, b, c);
    int abd = CCW(a, b, d);
    if (!abc && !abd) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    parent.assign(N, -1);
    vector<array<point, 2>> v(N);
    for (int i = 0; i < N; i++) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i][0][0] = (ll)(a * 100.0 + 0.5);
        v[i][0][1] = (ll)(b * 100.0 + 0.5);
        v[i][1][0] = (ll)(c * 100.0 + 0.5);
        v[i][1][1] = (ll)(d * 100.0 + 0.5);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersect(v[i][0], v[i][1], v[j][0], v[j][1])) Union(i, j);
        }
    }

    cout << count(parent.begin(), parent.end(), -1);
}