#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        s.insert(a);
    }

    int mn = 5;
    for (auto& i : s) {
        int cnt = 0;
        for (int j = 1; j < 5; j++) {
            cnt += s.find(i + j) == s.end();
        }
        mn = min(mn, cnt);
    }

    cout << mn;
}