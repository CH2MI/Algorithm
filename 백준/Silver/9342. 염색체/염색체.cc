#include <bits/stdc++.h>
using namespace std;

bool check(const string& s) {
    regex r("\\b[A-F]?A+F+C+[A-F]?\\b");
    return regex_match(s, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;

        if (check(s)) cout << "Infected!\n";
        else cout << "Good\n";
    }
}
