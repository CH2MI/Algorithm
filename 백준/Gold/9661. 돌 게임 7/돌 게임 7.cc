#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    if (N % 5 == 0 || N % 5 == 2) cout << "CY";
    else cout << "SK";
}