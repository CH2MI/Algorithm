#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if (a == "null") {
        cout << "NullPointerException\nNullPointerException";
    }
    else if (b == "null") {
        cout << "false\nfalse";
    }
    else {
        if (a == b) cout << "true\n";
        else cout << "false\n";

        for (auto& c : a) if (c >= 'a') c = c - 'a' + 'A';
        for (auto& c : b) if (c >= 'a') c = c - 'a' + 'A';

        if (a == b) cout << "true";
        else cout << "false";
    }

}