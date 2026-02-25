#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;

    string pattern; cin >> pattern;

    auto idx = pattern.find('*');
    pattern.insert(idx, "[a-z]");
    pattern = "\\b" + pattern + "\\b";

    for (int i = 0; i < N; i++) {
        string s; cin >> s;

        if (regex_match(s, regex(pattern))) cout << "DA\n";
        else cout << "NE\n";
    }
}
