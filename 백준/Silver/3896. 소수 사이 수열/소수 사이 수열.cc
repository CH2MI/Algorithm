#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1299710;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int> primes, isPrime(MAX, 1);
    primes.reserve(MAX);
    for (int i = 2; i * i < MAX; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j <= MAX; j += i) isPrime[j] = 0;
    }

    for (int i = 2; i <= MAX; i++) if (isPrime[i]) primes.push_back(i);

    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        if (isPrime[k]) cout << "0\n";
        else {
            auto itr = upper_bound(primes.begin(), primes.end(), k);
            cout << *itr - *(itr - 1) << '\n';
        }
    }
}