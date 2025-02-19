#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int cnt = 0;
    for (int i = 5; i <= N; i *= 5) {
        cnt += N / i;
    }
    cout << cnt;
}