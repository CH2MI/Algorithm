#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
typedef long long ll;

int L;
string s;
const ll MOD[2] = {1000000007, 1000000009};
const ll base = 26;
vector<ll> power[2], psum[2];

ll getHash(int s, int e) {
    ll ret[2];
    for (int k = 0; k < 2; k++) {
        ret[k] = (psum[k][e] - psum[k][s - 1] + MOD[k]) % MOD[k];
        ret[k] = (ret[k] * power[k][L - s]) % MOD[k];
    }
    return ret[0] * MOD[1] + ret[1];
}

bool solve(int mid) {
    unordered_set<ll> set;
    for (int i = 1; i <= L - mid + 1; i++) {
        set.insert(getHash(i, i + mid - 1));
    }
    return (int)set.size() != L - mid + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> L >> s;
    power[0].assign(L + 1, 0); power[1].assign(L + 1, 0);
    psum[0].assign(L + 1, 0); psum[1].assign(L + 1, 0);

    power[0][0] = power[1][0] = 1;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= L; i++) {
            power[k][i] = (power[k][i - 1] * base) % MOD[k];
            psum[k][i] = (psum[k][i - 1] + (s[i - 1] - 'a') * power[k][i]) % MOD[k];
        }
    }

    int lo = 0, hi = L;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
}