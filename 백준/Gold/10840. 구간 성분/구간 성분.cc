#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const long long MOD[2] = {1000000007, 1000000009};
const long long base = 1501;
string A, B;
int Alen, Blen;
vector<long long> Asum[2], Bsum[2];
long long power[26][2];

bool solve(int mid) {
    unordered_set<long long> hashset[2];
    for (int i = 1; i <= Alen - mid + 1; i++) {
        hashset[0].insert((Asum[0][i + mid - 1] - Asum[0][i - 1] + MOD[0]) % MOD[0]);
        hashset[1].insert((Asum[1][i + mid - 1] - Asum[1][i - 1] + MOD[1]) % MOD[1]);
    }
    for (int j = 1; j <= Blen - mid + 1; j++) {
        long long a = (Bsum[0][j + mid - 1] - Bsum[0][j - 1] + MOD[0]) % MOD[0], b = (Bsum[1][j + mid - 1] - Bsum[1][j - 1] + MOD[1]) % MOD[1];
        if (hashset[0].find(a) != hashset[0].end() && hashset[1].find(b) != hashset[1].end()) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    power[0][0] = power[0][1] = 1;

    for (int i = 1; i < 26; i++) {
        power[i][0] = power[i - 1][0] * base % MOD[0];
        power[i][1] = power[i - 1][1] * base % MOD[1];
    }

    cin >> A >> B;

    Alen = (int)A.size();
    Blen = (int)B.size();

    Asum[0].assign(Alen + 1, 0); Asum[1].assign(Alen + 1, 0);
    Bsum[0].assign(Blen + 1, 0); Bsum[1].assign(Blen + 1, 0);

    for (int i = 1; i <= Alen; i++) {
        Asum[0][i] = (Asum[0][i - 1] + power[A[i - 1] - 'a'][0]) % MOD[0];
        Asum[1][i] = (Asum[1][i - 1] + power[A[i - 1] - 'a'][1]) % MOD[1];
    }
    for (int i = 1; i <= Blen; i++) {
        Bsum[0][i] = (Bsum[0][i - 1] + power[B[i - 1] - 'a'][0]) % MOD[0];
        Bsum[1][i] = (Bsum[1][i - 1] + power[B[i - 1] - 'a'][1]) % MOD[1];
    }

    int i = min(Alen, Blen);
    for (; i > 0; i--) {
        if (solve(i)) break;
    }
    cout << i;
}