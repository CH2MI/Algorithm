#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    vector<int> level(11);
    for (int& i : level) cin >> i;
 
    int sum = 0;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int b, s; float l;
        cin >> b >> l >> s;
 
        if (l >= 2.0 && s >= 17) sum += level[b];
    }
 
    cout << sum;
}
