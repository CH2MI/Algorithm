#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;
    
    int cnt = 0;
    int num = 1;

    for (int i : v) {
        if (i != num) cnt++;
        else num++;
    }

    cout << cnt;
     
}

