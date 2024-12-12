#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<long long> v(N);
    for (auto& i : v) cin >> i;
    long long B, C; cin >> B >> C;
    long long cnt = 0;
    for (auto i : v) {
        if (i <= B) cnt++;
        else cnt += (i - B - 1) / C + 2;
    }
    cout << cnt;
}
