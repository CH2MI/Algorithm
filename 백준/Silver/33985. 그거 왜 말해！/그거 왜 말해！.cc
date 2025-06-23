#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    string s; cin >> s;

    if (s.front() == 'B' || s.back() == 'A') cout << "No";
    else cout << "Yes";
}