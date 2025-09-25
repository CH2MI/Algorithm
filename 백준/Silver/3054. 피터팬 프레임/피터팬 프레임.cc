#include <bits/stdc++.h>
using namespace std;

string f[5] = {"..#..", ".#.#.", "#...#", ".#.#.", "..#.."};
string w[5] = {"..*..", ".*.*.", "*...*", ".*.*.", "..*.."};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;

    string ans[5];
    for (int i = 0; i < 5; i++) {
        ans[i] = f[i];
        if (i == 2) {
            *(ans[i].rbegin() + 2) = s[0];
        }
    }

    for (int i = 1; i < (int)s.size(); i++) {
        if ((i + 1) % 3) {
            for (int j = 0; j < 5; j++) {
                ans[j] += f[j].substr(1);
                if (j == 2) {
                    *(ans[j].rbegin() + 2) = s[i];
                }
            }
        }
        else {
            for (int j = 0; j < 5; j++) {
                ans[j].pop_back();
                ans[j] += w[j];
                if (j == 2) {
                    *(ans[j].rbegin() + 2) = s[i];
                }
            }
        }
    }

    for (auto& s : ans) cout << s << '\n';
}
