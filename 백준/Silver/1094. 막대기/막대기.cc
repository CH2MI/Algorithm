#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x;
    int cnt = 0;
    for (int i = 1; i <= 64; i <<= 1)
        cnt += (x & i) != 0;

    cout << cnt;
}
