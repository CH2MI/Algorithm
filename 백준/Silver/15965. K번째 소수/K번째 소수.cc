#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 10'000'000;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<int> is_prime(MAX + 1, 1);
    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i]) continue;

        for (int j = i + i; j <= MAX; j += i) is_prime[j] = 0;
    }

    vector<int> p; p.reserve(500'000);

    for (int i = 2; i <= MAX; i++) if (is_prime[i]) p.push_back(i);

    int K; cin >> K;
    cout << p[K - 1];
}
