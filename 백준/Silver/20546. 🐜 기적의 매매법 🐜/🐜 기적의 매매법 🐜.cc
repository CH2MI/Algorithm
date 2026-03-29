#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<int> v(14);
    for (int& i : v) cin >> i;

    int J = N, jcnt = 0;
    for (int i = 0; i < 14; i++) {
        if (J >= v[i]) {
            jcnt += J / v[i];
            J -= v[i] * (J / v[i]);
        }
    }
    J += jcnt * v.back();

    int S = N, scnt = 0, t = 0;
    for (int i = 3; i < 14; i++) {
        if (v[i - 3] < v[i - 2] && v[i - 2] < v[i - 1] && v[i - 1] < v[i]) {
            S += scnt * v[i];
            scnt = 0;
        }
        if (v[i - 3] > v[i - 2] && v[i - 2] > v[i - 1] && v[i - 1] > v[i]) {
            scnt += S / v[i];
            S -= v[i] * (S / v[i]);
        }
    }
    S += scnt * v.back();
    
    if (J < S) cout << "TIMING";
    else if (J > S) cout << "BNP";
    else cout << "SAMESAME";

}
