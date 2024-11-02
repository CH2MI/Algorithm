#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
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
    int nodeIndex;
public:
    Trie() {
        nodes.emplace_back();
        nodeIndex = 1;
    }
    vector<node> nodes;
    void push(const string& s);
};

void Trie::push(const string& s) {
    int i = 0;
    for (const auto& c : s) {
        if (nodes[i].childs.find(c) == nodes[i].childs.end()) {
            nodes.emplace_back(c);
            nodes[i].childs[c] = nodeIndex++;
        }
        i = nodes[i].childs[c];
    }
    nodes[i].isLeaf = true;
}

Trie color;
unordered_set<string> name;

bool IsName(const string& s, int index) {
    int len = (int)s.size() - index;
    return name.find(s.substr(index, len)) != name.end();
}

bool IsPossible(const string& s) {
    int n = 0;
    bool f = false;
    for (int i = 0; i < (int)s.size(); i++) {
        if (color.nodes[n].childs.find(s[i]) != color.nodes[n].childs.end()) {
            n = color.nodes[n].childs[s[i]];
            if (color.nodes[n].isLeaf) f |= IsName(s, i + 1);
        }
        else {
           break;
        }
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int C, N; cin >> C >> N;
    for (int i = 0; i < C; i++) {
        string s; cin >> s;
        color.push(s);
    }
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        name.insert(s);
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        string s; cin >> s;
        if (IsPossible(s)) cout << "Yes\n";
        else cout << "No\n";
    }
}