#include <bits/stdc++.h>
using namespace std;

typedef array<long long, 2> point;

long long dist(point& a, point& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        array<point, 4> v;
        for (int i = 0; i < 4; i++) {
            cin >> v[i][0] >> v[i][1];
        }

        vector<vector<long long>> dists(4);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                dists[i].push_back(dist(v[i], v[j]));
            }
            sort(dists[i].begin(), dists[i].end());
        }

        if (dists[0] == dists[1] && dists[0] == dists[2] && dists[0] == dists[3]) {
            if (dists[0][0] == dists[0][1] && dists[0][0] * 2 == dists[0][2]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else cout << 0 << '\n';


    }
}