#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    long long sum = 1;

    int len = 1;
    for (int i = 1; i < N; i++) {
        if (v[i - 1] <= v[i]) {
            len += 1;
        }
        else {
            len = 1;
        }
        sum += len;
    }
    cout << sum;
}