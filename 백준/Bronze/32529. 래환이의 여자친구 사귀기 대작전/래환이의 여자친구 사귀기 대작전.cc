#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    int sum = 0;
    auto itr = v.rbegin();
    for (; itr != v.rend(); itr++) {
        sum += *itr;
        if (sum >= M) break;
    }

    if (itr == v.rend()) cout << -1;
    else cout << distance(v.begin(), itr.base());
}