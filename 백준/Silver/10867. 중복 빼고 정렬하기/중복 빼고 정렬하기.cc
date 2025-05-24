#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        s.insert(a);
    }

    for (int i : s) cout << i << ' ';
}