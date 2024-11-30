#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool solve(long long mid, long long cnt) {
    long long sum = 0;
    for (int& i : v) sum += mid / i;
    return sum >= cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M; cin >> N >> M;
    v.assign(N, 0);

    int mx = 0;
    for (int& i : v) cin >> i, mx = max(mx, i);

    long long lo = 1, hi = mx * M;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (solve(mid, M)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}