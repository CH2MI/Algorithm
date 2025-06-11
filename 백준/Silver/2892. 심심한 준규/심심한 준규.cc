#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s.front() < '4') cout << '.';
        else cout << '-';
    }
}