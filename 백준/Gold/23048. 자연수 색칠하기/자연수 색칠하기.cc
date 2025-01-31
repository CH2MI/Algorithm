#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> v(N + 1);
    int C = 2;
    v[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (v[i]) continue;
        for (int j = i; j <= N; j += i) {
            if (v[j]) continue;
            v[j] = C;
        }
        C++;
    }
    cout << C - 1 << '\n';
    for (int i = 1; i <= N; i++) cout << v[i] << ' ';
}