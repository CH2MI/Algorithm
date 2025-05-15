#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long N; cin >> N;
    int cnt = 0;
    for (long long i = 1; i * i <= N; i++) ++cnt;
    cout << cnt;
}