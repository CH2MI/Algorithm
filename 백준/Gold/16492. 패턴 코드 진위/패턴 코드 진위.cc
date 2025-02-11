#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> gen;
unordered_set<string> del;

bool is_possible(string start, string& target) {
    if (start == target) return 1;
    for (int i = 0; i < 10; i++) {
        string a, b;
        for (auto c : start) {
            if (gen.find(c) != gen.end()) {
                a += gen[c];
            }
            else a += c;
        }

        vector<int> v(a.size());
        for (int j = 0; j < v.size(); j++) {
            for (auto& s : del) {
                if (j + s.size() <= v.size() && a.substr(j, s.size()) == s) fill(v.begin() + j, v.begin() + j + s.size(), 1);
            }
        }
        for (int j = 0; j < a.size(); j++) {
            if (!v[j]) b += a[j];
        }
        
        if (b == target) return 1;
        start = b;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string start = "A", target;
    while (true) {
        string s; cin >> s;
        if (s == "gen:") {
            char a;
            string b, c;
            cin >> a >> b >> c;
            gen.emplace(a, c);
        }
        else if (s == "del:") {
            string a; cin >> a;
            del.insert(a);
        }
        else {
            cin >> target;
            break;
        }
    }

    if (is_possible(start, target)) cout << 'O';
    else cout << 'X';
}

