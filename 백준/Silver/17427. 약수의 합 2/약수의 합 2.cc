#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    constexpr int MAX = 1'000'000;

    array<int, MAX + 1> arr{};

    for (int i = 1; i <= MAX; i++) {
        for (int j = i; j <= MAX; j += i) arr[j] += i;
    }

    vector<long long> psum(MAX + 1);
    for (int i = 1; i <= MAX; i++) {
        psum[i] = psum[i - 1] + arr[i];
    }

    int N; cin >> N;
    cout << psum[N];
}
