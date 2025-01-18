#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int root;
vector<int> v;
vector<vector<int>> adj;

int cnt, f;
int DFS(int p, int cur, int max, int k) {
    if (v[cur] > max || cnt >= k) {
        f = 1;
        return 0;
    }
    
    vector<int> a;
    for (int& nxt : adj[cur]) {
        if (nxt == p) continue;
        a.push_back(DFS(cur, nxt, max, k));
    }
    
    if (a.size() > 0 && v[cur] + a[0] > max) {
        a[0] = 0;
        cnt++;
    }
    if (a.size() > 1 && v[cur] + a[1] > max) {
        a[1] = 0;
        cnt++;
    }
    if (a.size() > 1 && v[cur] + a[0] + a[1] > max) {
        if (a[0] > a[1]) a[0] = 0;
        else a[1] = 0;
        cnt++;
    }
    if (a.size() == 0) return v[cur];
    if (a.size() == 1) return v[cur] + a[0];
    return v[cur] + a[0] + a[1];
}

bool solve(int mid, int k) {
    cnt = 0;
    f = 0;
    DFS(-1, root, mid, k);
    if (f) return 0;
    return cnt <= k - 1;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    v = num;
    adj.assign(num.size(), vector<int>());
        
    vector<int> r(num.size());
    for (int i = 0; i < links.size(); i++) {
        if (links[i][0] != -1) {
            r[links[i][0]]++;
            adj[i].push_back(links[i][0]);
            adj[links[i][0]].push_back(i);
        }
        if (links[i][1] != -1) {
            r[links[i][1]]++;
            adj[i].push_back(links[i][1]);
            adj[links[i][1]].push_back(i);
        }
    }
    root = min_element(r.begin(), r.end()) - r.begin();
    int lo = 0, hi = accumulate(v.begin(), v.end(), 1);
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid, k)) hi = mid;
        else lo = mid;
    }
    return hi;
}