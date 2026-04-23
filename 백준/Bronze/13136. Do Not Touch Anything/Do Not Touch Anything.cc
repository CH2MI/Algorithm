#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    long long R, C, N; cin >> R >> C >> N;
    cout << ((R - 1) / N + 1) * ((C - 1) / N + 1); 

}
