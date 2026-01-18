#include <bits/stdc++.h>
using namespace std;

vector<int> isprime(1000, 1);
vector<int> primes;

void sovle() {
    int l = (int)primes.size();

    int N; cin >> N;

    for (int i = 0; i < l; i++) {
        for (int j = i; j < l; j++) {
            for (int k = j; k < l; k++) {
                if (primes[i] + primes[j] + primes[k] == N) {
                    cout << primes[i] << ' ' << primes[j] << ' ' << primes[k] << '\n';
                    return;
                }
            }
        }
    }

    cout << 0 << '\n';
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif


    for (int i = 2; i < 1000; i++) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < 1000; j += i) {
            isprime[j] = 0;
        }
    }
    int T; cin >> T;
    while (T--) {
        sovle();
    }
}
