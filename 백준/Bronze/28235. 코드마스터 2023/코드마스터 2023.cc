#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string s; cin >> s;
    if (s[0] == 'S') cout << "HIGHSCHOOL";
    if (s[0] == 'C') cout << "MASTER";
    if (s[0] == '2') cout << "0611";
    if (s[0] == 'A') cout << "CONTEST";
}
