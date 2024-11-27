#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<point> points(3);
    vector<vector<point>> v(3, vector<point>());
    for (int i = 0; i < 3; i++) cin >> points[i].x >> points[i].y;

    for (int i = 0; i < 3; i++) {
        ll dx = points[(i + 1) % 3].x - points[i].x;
        ll dy = points[(i + 1) % 3].y - points[i].y;

        ll g = gcd(dx, dy);
        if (g == 1) {
            cout << -1;
            return 0;
        }
        point p1 = {points[i].x + dx / g, points[i].y + dy / g};
        point p2 = {points[(i + 1) % 3].x - dx / g, points[(i + 1) % 3].y - dy / g};
        point p3 = {points[i].x + dx / g * (g / 2), points[i].y + dy / g * (g / 2)};
        point p4 = {points[(i + 1) % 3].x - dx / g * (g / 2), points[(i + 1) % 3].y - dy / g * (g / 2)};
        v[i].push_back(p1); v[i].push_back(p2); v[i].push_back(p3); v[i].push_back(p4);
    }

    ll mx = 0;
    ll mn = LLONG_MAX;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                ll area = abs(v[0][i].x * v[1][j].y + v[1][j].x * v[2][k].y + v[2][k].x * v[0][i].y - (v[1][j].x * v[0][i].y + v[2][k].x * v[1][j].y + v[0][i].x * v[2][k].y));
                mx = max(mx, area);
                mn = min(mn, area);
            }
        }
    }
    cout << mx << ' ' << mn;
}