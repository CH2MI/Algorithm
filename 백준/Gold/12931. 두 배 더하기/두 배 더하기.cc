#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    int cnt = 0;
    for (int& i : v) if (i % 2) --i, cnt++;
    while (count(v.begin(), v.end(), 0) != N) {
        for (int& i : v) {
            i /= 2;
        }
        ++cnt;
        for (int& i : v) if (i % 2) --i, cnt++;
    }
    cout << cnt;
    return 0;

}