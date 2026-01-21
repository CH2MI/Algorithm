#include <bits/stdc++.h>
using namespace std;

int N, cnt;
string s, ans;
vector<int> visited;

int go() {
    if (s.size() == ans.size()) {
        if (!--cnt) {
            cout << s << ' ' << N << " = " << ans << '\n';
            return 1;
        }
    }

    int f = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (visited[i]) continue;

        ans.push_back(s[i]);
        visited[i] = 1;
        f |= go();
        visited[i] = 0;
        ans.pop_back();
    }

    return f;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif



    while (cin >> s >> N) {
        visited.assign(s.size(), 0);
        cnt = N;
        if (!go()) cout << s << ' ' << N << " = No permutation\n";
    }

}
