#include <iostream>
#define MOD 1234567891
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; string s;
    cin >> N >> s;
    long long sum = 0, b = 31, r = 1;

    for (const auto& c : s) {
        sum = (sum + ((c - 'a' + 1) * r) % MOD) % MOD;
        r = r * b % MOD;
    }
    cout << sum;
}