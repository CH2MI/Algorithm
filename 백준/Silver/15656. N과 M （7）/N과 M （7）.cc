#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v, selected;

void go(int cnt) {
    if (cnt == M) {
        for (int i : selected) cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i : v) {
        selected.push_back(i);
        go(cnt + 1);
        selected.pop_back();
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;
    v.assign(N, 0);
    for (int& i : v) cin >> i;

    sort(v.begin(), v.end());

    go(0);

}