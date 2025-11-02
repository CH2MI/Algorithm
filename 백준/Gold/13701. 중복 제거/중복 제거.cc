#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    bitset<33554433> bs;

    int a;
    while (cin >> a) {
        if (!bs[a]) {
            cout << a << ' ';
            bs[a] = 1;
        }
    }
}