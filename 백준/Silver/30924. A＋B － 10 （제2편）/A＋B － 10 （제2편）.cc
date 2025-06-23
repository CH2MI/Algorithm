#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int A, B, ans;

    vector<int> v(10000);
    for (int i = 0; i < 10000; i++) v[i] = i + 1;

    shuffle(v.begin(), v.end(), random_device{});

    for (int i : v) {
        cout << "? A " << i << endl;
        cin >> ans;
        if (ans) {
            A = i;
            break;
        }
    }
    for (int i : v) {
        cout << "? B " << i << endl;
        cin >> ans;
        if (ans) {
            B = i;
            break;
        }
    }

    cout << "! " << A + B;
}