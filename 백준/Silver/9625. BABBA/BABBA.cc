#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;

    int a = 1, b = 0;

    for (int i = 0; i < N; i++) {
        int ta = b;
        int tb = a + b;
        a = ta, b = tb;
    }

    cout << a << ' ' << b;


}