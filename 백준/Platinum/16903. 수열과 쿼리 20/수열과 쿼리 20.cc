#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    int cnt;
    int pre = -1;
    int nxt[2] = {-1, -1};
};

class Trie {
public:
    Trie();
    void push(int x);
    void pop(int x);
    int find(int x);

private:
    int sz;
    unordered_map<int, node> nodes;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    Trie trie;
    trie.push(0);
    for (int i = 0; i < N; i++) {
        int q, a; cin >> q >> a;

        if (q == 1) {
            trie.push(a);
        }
        else if (q == 2) {
            trie.pop(a);
        }
        else {
            cout << trie.find(a) << '\n';
        }
    }
}

Trie::Trie() {
    nodes = {};
    nodes[0] = node{};
    sz = 1;
}

void Trie::push(int x) {
    int cur = 0;

    for (int i = (1 << 30); i; i >>= 1) {
        int j = (x & i) != 0;

        if (nodes[cur].nxt[j] == -1) {
            nodes[cur].nxt[j] = sz;
            nodes[sz].value = nodes[cur].value | (x & i);
            nodes[sz].pre = cur;
            sz++;
        }
        cur = nodes[cur].nxt[j];
    }

    nodes[cur].cnt++;
}

void Trie::pop(int x) {
    int cur = 0;

    for (int i = (1 << 30); i; i >>= 1) {
        int j = (x & i) != 0;

        cur = nodes[cur].nxt[j];
    }

    if (--nodes[cur].cnt > 0) return;

    while (cur != 0) {
        int pre = nodes[cur].pre;
        nodes.erase(cur);

        if (nodes[pre].nxt[0] == cur) {
            nodes[pre].nxt[0] = -1;
            if (nodes[pre].nxt[1] != -1) return;
        }
        else {
            nodes[pre].nxt[1] = -1;
            if (nodes[pre].nxt[0] != -1) return;
        }
        cur = pre;
    }
}

int Trie::find(int x) {
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

