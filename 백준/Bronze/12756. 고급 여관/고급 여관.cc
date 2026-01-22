#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int aa, ah, ba, bh; cin >> aa >> ah >> ba >> bh;

    int ac = (bh / aa) + (bh % aa != 0);
    int bc = (ah / ba) + (ah % ba != 0);
    
    if (ac < bc) cout << "PLAYER A";
    else if (ac > bc) cout << "PLAYER B";
    else cout << "DRAW";

}
