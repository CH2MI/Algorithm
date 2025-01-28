#include <bits/stdc++.h>
using namespace std;

typedef array<double, 2> point;

double CCW(point& a, point& b, point& c) {
    return a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
}

double Area(vector<point>& p) {
    double ret = 0;
    for (int i = 1; i < p.size() - 1; i++) {
        ret += abs(CCW(p[0], p[i], p[i + 1])) / 2;
    }
    return ret;
}

void cal(double a, vector<point> p, double& mn, double& mx) {
    double l = Area(p), r = a - l;
    if (abs(mn - mx) > abs(l - r)) mn = min(l, r), mx = max(l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<point> p(4), m(p);
    for (int i = 0; i < 4; i++) cin >> p[i][0] >> p[i][1];
    for (int i = 0; i < 4; i++) {
        m[i][0] = (p[i][0] + p[(i + 1) % 4][0]) / 2;
        m[i][1] = (p[i][1] + p[(i + 1) % 4][1]) / 2;
    }
    vector<point> v;
    for (int i = 0; i < 4; i++) v.push_back(p[i]), v.push_back(m[i]);

    double a = Area(p);

    double l = 0, r = a;
    for (int i = 0; i < 8; i++) {
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 3) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 3) % 8], v[(i + 4) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 3) % 8], v[(i + 4) % 8], v[(i + 5) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 3) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 3) % 8], v[(i + 5) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 5) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 4) % 8], v[(i + 5) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 3) % 8], v[(i + 4) % 8], v[(i + 5) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
        cal(a, {v[i], v[(i + 1) % 8], v[(i + 2) % 8], v[(i + 5) % 8], v[(i + 6) % 8], v[(i + 7) % 8]}, l, r);
    }

    cout << fixed;
    cout.precision(3);
    cout << l << ' ' << r;

}