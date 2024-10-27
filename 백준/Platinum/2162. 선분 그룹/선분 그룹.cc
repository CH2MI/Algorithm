#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<double, double> point;
typedef pair<point, point> line;

int CCW(const point& A, const point& B, const point& C) {
    double ret = (A.x * B.y + B.x * C.y + C.x * A.y) - (B.x * A.y + C.x * B.y + A.x * C.y);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    return 0;
}

double GetDist(const line& A) {
    double x = A.second.x - A.first.x;
    double y = A.second.y - A.first.y;
    return sqrt(x * x + y * y);
}

bool IsCross(const line& A, const line& B) {
    int x = CCW(A.first, A.second, B.first) * CCW(A.first, A.second, B.second);
    int y = CCW(B.first, B.second, A.first) * CCW(B.first, B.second, A.second);

    if (x > 0 || y > 0) return false;
    if (y < 0) return true;

    double Adist = GetDist(A), Bdist = GetDist(B);
    double dist = max({GetDist({A.first, B.first}), GetDist({A.first, B.second}), GetDist({A.second, B.first}), GetDist({A.second, B.second})});

    if (dist > Adist + Bdist) return false;
    return true;
}

vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);

    if (A == B) return;

    parent[B] = A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<line> v(N);
    for (auto& i : v) cin >> i.first.x >> i.first.y >> i.second.x >> i.second.y;
    parent.assign(N, -1);

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (IsCross(v[i], v[j])) Union(i, j);
        }
    }

    vector<int> count(N);
    for (int i = 0; i < N; i++) {
        int p = Find(i);
        count[p]++;
    }

    int cnt = 0, mx = 0;
    for (int i = 0; i < N; i++) {
        if (!count[i]) continue;
        cnt++;
        mx = max(mx, count[i]);
    }
    
    cout << cnt << '\n' << mx;
}