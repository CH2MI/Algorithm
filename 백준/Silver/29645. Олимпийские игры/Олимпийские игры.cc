#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    map<string, tuple<int, int, int>> m;

    for (int i = 0; i < n; i++) {
        string G, S, B;
        cin >> G >> S >> B;
        auto& [gg, gs, gb] = m[G]; gg++;
        auto& [sg, ss, sb] = m[S]; ss++;
        auto& [bg, bs, bb] = m[B]; bb++;
    }

    vector<pair<string, tuple<int, int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [&](pair<string, tuple<int, int, int>>& a, pair<string, tuple<int, int, int>>& b) {
        auto& [ag, as, ab] = a.second;
        auto& [bg, bs, bb] = b.second;
        if (ag == bg && as == bs && ab == bb) return a.first < b.first;
        if (ag == bg && as == bs) return ab > bb;
        if (ag == bg) return as > bs;
        return ag > bg;
    });

    cout << v.front().first;

}