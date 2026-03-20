#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string s; cin >> s;
    unordered_map<char, unordered_map<int, int>> m;

    bool du = false;
    for (int i = 0; i < s.size(); i += 3) {
        string card = s.substr(i, 3);
        int num = stoi(card.substr(1));

        if (++m[card[0]][num] > 1) du = true;
    }

    if (du) cout << "GRESKA";
    else cout << 13 - m['P'].size() << ' ' << 13 - m['K'].size() << ' ' << 13 - m['H'].size() << ' ' << 13 - m['T'].size();


}
