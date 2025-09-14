#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;

    long long sum = 0;
    int i;
    for (i = 1; i <= N; i *= 10) {
        sum += N - i + 1;
    }
    cout << sum;

}