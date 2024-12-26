#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v;
    for (int i = 0; i < 225; i++) {
        char a; cin >> a;
        if (a == 'w') v = 0;
        else if (a == 'b') v = 1;
        else if (a == 'g') v = 2;
    }
    if (!v) cout << "chunbae";
    else if (v == 1) cout << "nabi";
    else cout << "yeongcheol";

}