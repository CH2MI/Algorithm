#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll arr[40] = {1};
    for (int i = 1; i < 40; i++) arr[i] = arr[i - 1] * 3;
    int T; cin >> T;
    while (T--) {
        vector<ll> v;
        v.reserve(40);
        ll a; cin >> a;
        while (a > 0) {
            v.push_back(a % 2);
            a >>= 1;
        }
        ll sum = 0;
        int l = (int)v.size() - 1;
        for (int i = l; i >= 0; i--) {
            if (v[i]) sum += arr[i];
        }
        cout << sum << '\n';
    }
}