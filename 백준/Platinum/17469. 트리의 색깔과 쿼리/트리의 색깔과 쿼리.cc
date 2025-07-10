#include <bits/stdc++.h>
using namespace std;

class uf {
public:
    uf(int n) {
        v.assign(n, -1);
        parent.assign(n, -1);
        s.assign(n, set<int>());
    }

    void SetParent(int p, int i) { v[i] = p; }
    void SetColor(int c, int i) { s[i].insert(c); }

    void Query1(int a) {
        parent[a] = v[a];
        Find(a);
    }

    int Query2(int a) { return s[Find(a)].size(); }
private:

    int Find(int x) {
        if (parent[x] == -1) return x;

        int p = Find(parent[x]);
        parent[x] = p;
        if (s[x].size() > s[p].size()) swap(s[x], s[p]);
        for (int i : s[x]) s[p].insert(i);
        s[x] = move(set<int>());
        return p;
    }

    vector<int> v, parent;
    vector<set<int>> s;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    uf uf(N);
    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        uf.SetParent(a - 1, i);
    }
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        uf.SetColor(a, i);
    }

    stack<array<int, 2>> st;
    for (int i = 0; i < N - 1 + Q; i++) {
        int a, b; cin >> a >> b;
        st.push({a, b});
    }

    stack<int> ans;
    for (; !st.empty(); st.pop()) {
        auto [a, b] = st.top();
        if (a == 1) uf.Query1(b - 1);
        else ans.push(uf.Query2(b - 1));
    }

    for (; !ans.empty(); ans.pop()) {
        cout << ans.top() << '\n';
    }
}