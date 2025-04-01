#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (1) {
        int a; cin >> a;
        if (a == -1) break;

        vector<int> v; v.reserve(a);
        for (int i = 1; i < a; i++) {
            if (a % i == 0) {
                v.push_back(i);
            }
        }

        if (accumulate(v.begin(), v.end(), 0) == a) {
            cout << a << " =";
            for (int i = 0; i < v.size(); i++) {
                cout << ' ' << v[i] << ' ' << "+\n"[i == v.size() - 1];
            }
        }
        else cout << a << " is NOT perfect.\n";
    }
}