#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<int> mx(N), mn(N);
    for (int& i : mx) cin >> i;
    for (int& i : mn) cin >> i;
    cout << accumulate(mx.begin(), mx.end(), 0, [] (int a, int b) { return a + abs(b);}) - accumulate(mn.begin(), mn.end(), 0, [] (int a, int b) { return a - abs(b);});
}