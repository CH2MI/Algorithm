#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Trie {
    struct node {
        char name;
        bool isLeaf;
        map<char, int> childs;
        node(char name = '\0', bool isLeaf = false) {
            this->name = name;
            this->isLeaf = isLeaf;
            childs = map<char, int>();
        }
    };
    vector<node> nodes;
    int nodeIndex;
    double sum;

public:
    Trie() {
        nodes = vector<node>();
        nodes.push_back(node());
        nodeIndex = 1;
    }
    void push(string s);
    void DFS(int n, int cnt);
    double count();
};

void Trie::push(string s) {
    int i = 0;
    for (const auto& c : s) {
        if (nodes[i].childs.find(c) == nodes[i].childs.end()) {
            nodes.emplace_back(c, false);
            nodes[i].childs[c] = nodeIndex++;
        }
        i = nodes[i].childs[c];
    }
    nodes[i].isLeaf = true;
}

void Trie::DFS(int n, int cnt) {
    if (nodes[n].isLeaf) sum += cnt;
    int size = nodes[n].childs.size();
    if (size == 1 && !nodes[n].isLeaf) DFS(nodes[n].childs.begin()->second, cnt);
    else {
        for (const auto& i : nodes[n].childs) DFS(i.second, cnt + 1);
    }
}

double Trie::count() {
    sum = 0;

    for (const auto& i : nodes[0].childs) {
        DFS(i.second, 1);
    }
    return (double)sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cout << fixed;
    cout.precision(2);
    int N;
    while (cin >> N) {
        Trie trie;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            trie.push(s);
        }
        cout << trie.count() / (double)N << '\n';
    }
}