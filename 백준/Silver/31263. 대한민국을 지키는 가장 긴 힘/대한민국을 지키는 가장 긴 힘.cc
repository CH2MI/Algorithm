#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < N;) {
        ++cnt;
        if (((i < N - 3 && s[i + 3] != '0') || i == N - 3) && stoi(s.substr(i, 3)) < 642 && stoi(s.substr(i, 3)) > 99) i += 3;
        else if (((i < N - 2 && s[i + 2] != '0') || i == N - 2) && stoi(s.substr(i, 2)) > 9) i += 2;
        else i++;
    }
    cout << cnt;
}