#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int M, N; cin >> M >> N;
    vector<pair<string, int>> v;
    for (int i = M; i <= N; i++) {
        string j = to_string(i);
        string s;
        for (auto c : j) {
            s += num[c - '0'];
        }
        v.push_back({s, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << ' ';
        if (i % 10 == 9) cout << '\n';
    }
}