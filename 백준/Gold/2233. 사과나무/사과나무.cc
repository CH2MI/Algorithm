#include <bits/stdc++.h>
using namespace std;

int N, l;
vector<int> level, parent;
vector<vector<int>> adj;

void DFS(int pre, int cur) {
    if (pre != -1) level[cur] = level[pre] + 1;
    parent[cur] = pre;

    for (int& nxt : adj[cur]) {
        if (nxt == pre) continue;
        DFS(cur, nxt);
    }
}

int LCA(array<int, 2> node) {
    int a = node[0], b = node[1];

    if (level[a] < level[b]) swap(a, b);
    while (level[a] != level[b]) a = parent[a];

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    string s; cin >> s;

    adj.assign(N, vector<int>());

    // 그래프를 만든다.
    stack<int> st;
    int n = 0;
    for (auto c : s) {
        if (c == '0') {
            if (!st.empty()) {
                adj[st.top()].push_back(n);
                adj[n].push_back(st.top());
            }
            st.push(n++);
        }
        else {
            st.pop();
        }
    }

    // 각 노드의 레벨을 구한다.
    level.assign(N, 0);
    parent.assign(N, -1);
    DFS(-1, 0);

    // 찾으려는 노드의 번호를 찾는다.
    array<int, 2> node{0, 0};
    for (int k = 0; k < 2; k++) {
        int p; cin >> p;
        st = stack<int>();
        n = 0;
        for (int i = 0; i < 2 * N; i++) {
            if (i == p - 1) {
                if (s[i] == '0') node[k] = n;
                else node[k] = st.top();
                break;
            }
            if (s[i] == '0') st.push(n++);
            else st.pop();
        }
    }

    // 최소 공통 조상을 찾는다.
    int a = LCA(node);

    // a번째 노드의 위치를 찾는다.
    st = stack<int>();
    n = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (s[i] == '0') {
            if (n == a) cout << i + 1 << ' ';
            st.push(n++);
        }
        else {
            if (st.top() == a) cout << i + 1;
            st.pop();
        }
    }
}
