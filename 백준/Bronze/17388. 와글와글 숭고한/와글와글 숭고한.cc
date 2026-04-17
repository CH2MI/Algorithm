#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int S, K, H;
    cin >> S >> K >> H;

    if (S + K + H >= 100) cout << "OK";
    else {
        int mn = min({S, K, H});

        if (mn == S) cout << "Soongsil";
        else if (mn == K) cout << "Korea";
        else cout << "Hanyang";
    }

}
