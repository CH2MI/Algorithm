#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    vector<int> v(5);
    for (int i = 0; i < T; i++) cin >>v[i];
    int sn = 0;
    if (v[0] > v[2]) sn += (v[0] - v[2]) * 508;
    else sn += (v[2] - v[0]) * 108;
    if (v[1] > v[3]) sn += (v[1] - v[3]) * 212;
    else sn += (v[3] - v[1]) * 305;
    sn += v[4] * 707;
    cout << sn * 4763;
}