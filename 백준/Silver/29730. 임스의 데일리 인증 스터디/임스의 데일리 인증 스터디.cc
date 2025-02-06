#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N; cin.ignore();
    vector<string> a, b;
    a.reserve(N); b.reserve(N);

    for (int i = 0; i < N; i++) {
        string s; getline(cin, s);
        if (s.size() > 7 && s.substr(0, 7) == "boj.kr/") {
            b.push_back(s);
        }
        else a.push_back(s);
    }
    sort(a.begin(), a.end(), [](auto& a, auto& b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });

    sort(b.begin(), b.end(), [](auto& a, auto& b) {
        int x = stoi(a.substr(7, 5)), y = stoi(b.substr(7, 5));
        return x < y;
    });

    for (auto& s : a) cout << s << '\n';
    for (auto& s : b) cout << s << '\n';
}