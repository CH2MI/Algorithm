#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    string s;

    int i = 0;
    for (; i < N - 2; i += 3) {
        s += "SSH";
    }

    if (N % 3) s += 'S';
    if (N % 3 == 2) s += 'S';

    cout << s;
}
