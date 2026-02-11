#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    array<float, 8> arr{};
    int n; cin >> n;
    for (int i = 0; i < 8; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());


    for (int i = 0; i < n - 8; i++) {
        cin >> arr.back();

        int j = 7;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            --j;
        }
    }

    cout << fixed << setprecision(3);

    for (int i = 0; i < 7; i++) cout << arr[i] << '\n';

}
