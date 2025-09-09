#include <bits/stdc++.h>
using namespace std;

struct node {
    int value = 0;
    int nxt[2]{-1, -1};
};

class Trie {
public:

    Trie() {
        nodes = {};
        nodes.emplace_back();
        sz = 1;
    }


    void push(int x) {
        int cur = 0;

        for (int i = (1 << 30); i; i >>= 1) {
            int j = (x & i) != 0;

            if (nodes[cur].nxt[j] == -1) {
                nodes[cur].nxt[j] = sz++;
                nodes.emplace_back();
                nodes.back().value = nodes[cur].value | (x & i);
            }

            cur = nodes[cur].nxt[j];
        }
    }

    int find(int x) {
        int cur = 0;

        for (int i = (1 << 30); i; i >>= 1) {
            int j = (x & i) == 0;

            if (nodes[cur].nxt[j] == -1) {
                cur = nodes[cur].nxt[!j];
            }
            else {
                cur = nodes[cur].nxt[j];
            }
        }

        return x ^ nodes[cur].value;
    }

private:
    int sz;
    vector<node> nodes;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif


    Trie trie;
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        trie.push(v[i]);
    }

    int mx = 0;
    for (int i : v) {
        mx = max(mx, trie.find(i));
    }

    cout << mx;
}
