#include <bits/stdc++.h>
using namespace std;
 
int N;
vector<int> parent;
 
int Find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x]);
}
 
// c의 부모를 p로 설정한다.
void Union(int p, int c) {
    p = Find(p);
    c = Find(c);
 
    if (p == c) return;
 
    parent[c] = p;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif
 
    cin >> N;
    vector<int> v(N);
    parent.assign(N, -1);
    for (int& i : v) cin >> i;
 
    vector<int> values(300001, -1);
 
    for (int i = 0; i < N; i++) {
        if (values[v[i]] == -1)
            values[v[i]] = i;
        else
            Union(values[v[i]], i);
    }
 
    int M; cin >> M;
 
    for (int i = 0; i < M; i++) {
        int q; cin >> q;
 
        if (q == 1) {
            int x, y; cin >> x >> y;
 
 
            // x인 값이 없는 경우
            if (values[x] == -1) continue;
 
            // y인 값이 없는 경우는 x를 y로 바꿔준다.
            if (values[y] == -1) {
                v[values[x]] = y;
                values[y] = values[x];
            }
 
            // y인 값이 있다면 x의 부모를 y로 설정한다.
            else {
                Union(values[y], values[x]);
            }
            values[x] = -1;
        }
        else {
            int z; cin >> z;
            cout << v[Find(z - 1)] << '\n';
        }
 
    }
}
