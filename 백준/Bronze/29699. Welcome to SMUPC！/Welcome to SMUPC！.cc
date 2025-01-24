#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s("WelcomeToSMUPC");
    int N; cin >> N;
    cout << s[(N - 1) % s.size()];
}