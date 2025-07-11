#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; string s; int K;
    cin >> N >> s >> K;

    if (find(s.begin(), s.end(), '1') == s.end()) cout << "YES";
    else if (N < K) cout << "NO";
    else {
        if (find(s.end() - K, s.end(), '1') != s.end()) cout << "NO";
        else cout << "YES";
    }
}