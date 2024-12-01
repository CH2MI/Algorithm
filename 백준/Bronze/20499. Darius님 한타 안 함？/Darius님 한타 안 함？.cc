#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kda[3];
    string s, t; cin >> s;
    for (int i = 0, j = 0; i < s.size(); i++) {
        if (s[i] == '/') kda[j++] = stoi(t), t = "";
        else t += s[i];
    }
    kda[2] = stoi(t);
    if (!kda[1] || kda[0] + kda[2] < kda[1]) cout << "hasu";
    else cout << "gosu";
}