#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, L; cin >> N >> L;
    string s; 
    for (int i = 0; i < L - 1; i++) s += '1';
    s += '0' + N;
    cout << s;
}