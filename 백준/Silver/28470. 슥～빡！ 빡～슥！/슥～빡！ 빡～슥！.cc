#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<long long> v1(N), v2(N), v3(N);
    for (auto& i : v1) cin >> i;
    for (auto& i : v2) cin >> i;
    for (auto& i : v3) {
        double a; cin >> a;
        i = a * 10;
    }
 
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += max((v1[i] * v3[i]) / 10 - v2[i], v1[i] - (v2[i] * v3[i]) / 10);
    }
    cout << sum;

}
