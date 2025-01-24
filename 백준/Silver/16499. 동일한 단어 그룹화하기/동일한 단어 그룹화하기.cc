#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    unordered_map<string, int> map;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        map[s]++;
    }
    cout << map.size();
}