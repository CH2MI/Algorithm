#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> v(N);
    for (auto& i : v) cin >> i;
    long long mul = 1;
    for (auto i : v) mul *= i;
    long long sum = 0;
    for (auto i : v) sum += mul / i;

    long long g = gcd(sum, mul);
    cout << mul / g << '/' << sum / g;
}