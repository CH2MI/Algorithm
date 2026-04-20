#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    array<int, 4> arr{};
    for (int& i : arr) cin >> i;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int mn = INT_MAX;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            mn = min(mn, abs(arr[i] + arr[j] - (sum - (arr[i] + arr[j]))));
        }
    }

    cout << mn;
}
