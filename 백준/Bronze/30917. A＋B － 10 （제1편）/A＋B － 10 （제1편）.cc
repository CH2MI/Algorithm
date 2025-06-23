#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int A, B, ans;
    for (int i = 1; i <= 9; i++) {
        cout << "? A " << i << endl;
        cin >> ans;
        if (ans) {
            A = i;
            break;
        }
    }
    for (int i = 1; i <= 9; i++) {
        cout << "? B " << i << endl;
        cin >> ans;
        if (ans) {
            B = i;
            break;
        }
    }

    cout << "! " << A + B;
}