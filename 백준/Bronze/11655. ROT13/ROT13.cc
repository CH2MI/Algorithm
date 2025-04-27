#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; getline(cin, s);

    for (auto& c : s) {
        if (c >= 'a') {
            c -= 'a';
            c = (c + 13) % 26;
            c += 'a';
        }
        else if (c >= 'A') {
            c -= 'A';
            c = (c + 13) % 26;
            c += 'A';
        }
    }
    cout << s;
}