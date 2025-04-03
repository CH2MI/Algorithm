#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);


    int T; cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        getline(cin, s);

        string t;
        for (char& c : s) {
            if (c == ' ') {
                int sum = 0;
                for (char i : t) sum += i - 'a';
                if (sum % 27 == 26) cout << ' ';
                else cout << (char)(sum % 27 + 'a');
                t.clear();
            }
            else t += c;
        }
        int sum = 0;
        for (char i : t) sum += i - 'a';
        if (sum % 27 == 26) cout << ' ';
        else cout << (char)(sum % 27 + 'a');
        cout << '\n';
    }
}
