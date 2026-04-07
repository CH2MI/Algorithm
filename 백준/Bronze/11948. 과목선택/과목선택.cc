#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<int> v1(4), v2(2);
    for (int& i : v1) cin >> i;
    for (int& i : v2) cin >> i;

    cout << accumulate(v1.begin(), v1.end(), 0) - *min_element(v1.begin(), v1.end()) + *max_element(v2.begin(), v2.end());
}
