#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, string>& A, const pair<int, string>& B) {
    if (A.first == B.first) {
        return A.second < B.second;
    }
    return A.first > B.first;
}

int main() {
    int N; cin >> N;
    map<string, int> m;
    
    while (N--) {
        string t, n;
        cin >> t >> n;
        
        int duration = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
        m[n] += duration;
    }
    
    vector<pair<int, string>> v;
    
    for (auto& i : m) {
        int cost = 10;
        if (i.second > 100) {
            cost += ((i.second - 51) / 50) * 3;
        }
        v.push_back({cost, i.first});
    }
    sort(v.begin(), v.end(), cmp);
    
    for (auto& i : v) {
        cout << i.second << ' ' << i.first << '\n';
    }
    
}