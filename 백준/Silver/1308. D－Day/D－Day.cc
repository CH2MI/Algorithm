#include <bits/stdc++.h>
using namespace std;

int is_leaf(int a) {
    if (a % 400 == 0) return 1;
    if (a % 100 == 0) return 0;
    if (a % 4 == 0) return 1;
    return 0;
}

int convert(array<int, 3>& day) {
    int ret = 0;

    ret += (day[0] - 1) * 365;
    ret += (day[0] - 1) / 4;
    ret -= (day[0] - 1) / 100;
    ret += (day[0] - 1) / 400;

    for (int i = 1; i < day[1]; i++) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                ret += 31;
                break;
            case 4: case 6: case 9: case 11:
                ret += 30;
                break;
            case 2:
                ret += 28 + is_leaf(day[0]);
                break;
        }
    }
    ret += day[2];
    return ret;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    array<int, 3> v[2];
    for (auto& [y, m, d] : v) cin >> y >> m >> d;

    int ans = convert(v[1]) - convert(v[0]);

    array<int, 3> t = v[0];
    t[0] += 1000;
    if (ans < convert(t) - convert(v[0])) cout << "D-" << ans;
    else cout << "gg";
}