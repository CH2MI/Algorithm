#include <bits/stdc++.h>
using namespace std;

int solve(string& s) {
    vector<string> v(3);
    for (int i = 0; i < 3; i++) {
        v[i] = s.substr(i * 3, 3);
    }

    int x = count(s.begin(), s.end(), 'X'), o = count(s.begin(), s.end(), 'O');

    if (x != o + 1 && x != o) return 0;

    int O = 0, X = 0;

    for (int i = 0; i < 3; i++) {
        if (v[i] == "XXX") X = 1;
        if (v[i] == "OOO") O = 1;
        if (v[0][i] == v[1][i] && v[1][i] == v[2][i]) {
            if (v[0][i] == 'X') X = 1;
            if (v[0][i] == 'O') O = 1;
        }
    }
    if (v[0][0] == v[1][1] && v[1][1] == v[2][2]) {
        if (v[0][0] == 'X') X = 1;
        if (v[0][0] == 'O') O = 1;
    }
    if (v[2][0] == v[1][1] && v[1][1] == v[0][2]) {
        if (v[2][0] == 'X') X = 1;
        if (v[2][0] == 'O') O = 1;
    }

    if (x == o + 1 && X && !O) return 1;
    if (x == o && !X && O) return 1;
    if (x + o == 9 && !X && !O) return 1;
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (1) {
        string s; cin >> s;
        if (s == "end") break;
        if (solve(s)) cout << "valid\n";
        else cout << "invalid\n";
    }
}