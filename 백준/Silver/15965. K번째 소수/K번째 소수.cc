#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<int> is_prime(1'000'001, 1);
    for (int i = 2; i * i <= 1'000'000; i++) {
        if (!is_prime[i]) continue;

        for (int j = i + i; j <= 1'000'000; j += i) is_prime[j] = 0;
    }

    vector<int> p; p.reserve(500'000);

    for (int i = 2; i <= 1'000'000; i++) if (is_prime[i]) p.push_back(i);

    int K; cin >> K;
    cout << p[K - 1];
}
