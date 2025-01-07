#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> p;

    int N = 100003;
    vector<int> check(N + 1);
    for (int i = 2; i * i <= N; i++) {
        if (check[i]) continue;

        for (int j = i + i; j <= N; j += i) {
            check[j] = 1;
        }
    }

    for (int i = 2; i <= N; i++) if (!check[i]) p.insert(i);

    int T; cin >> T;
    while (T--) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            int a; cin >> a;
            sum += *p.lower_bound(a);
        }
        cout << sum << '\n';
    }

}