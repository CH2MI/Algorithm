#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());

    for (int& i : v) {
        if (i <= L) L++;
    }
    cout << L;
}