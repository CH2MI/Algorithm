#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int D, H, W; cin >> D >> H >> W;
    double r = D / sqrt(H * H + W * W);
    cout << (int)(H * r) << ' ' << (int)(W * r);
}
