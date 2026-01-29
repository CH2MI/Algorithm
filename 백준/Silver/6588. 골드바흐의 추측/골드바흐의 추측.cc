#include <bits/stdc++.h>
using namespace std;

constexpr int Max = 1000000;

vector<int> primes, isPrime;

void solve(int N) {

    for (int i = 0; i <= primes.size(); i++) {
        int a = primes[i], b = N - primes[i];
        if (!isPrime[b]) continue;
        cout << N << " = " << a << " + " << b << '\n';
        return;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    isPrime.assign(Max, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= Max; i++) {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j <= Max; j += i) isPrime[j] = 0;
    }

    while (1) {
        int N; cin >> N;
        if (!N) break;

        solve(N);
    }

}
