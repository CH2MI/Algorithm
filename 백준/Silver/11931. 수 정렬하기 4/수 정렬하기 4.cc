#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;

    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.rbegin(), v.rend());
    for (int i : v) cout << i << '\n';
}