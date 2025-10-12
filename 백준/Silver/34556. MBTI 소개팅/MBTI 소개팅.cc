#include <bits/stdc++.h>
using namespace std;
 
int N;
vector<string> a, b;
vector<int> visited;
 
int cal(string& a, string& b) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        cnt += a[i] != b[i];
    }
 
    return cnt;
}
 
int go(int n, int cur, int sum) {
    if (n == 0) return sum;
 
    int mx = 0;
 
    for (int j = 0; j < N; j++) {
        if (visited[j]) continue;
        visited[j] = 1;
        int score = cal(a[cur], b[j]);
        mx = max(mx, go(n - 1, cur + 1, sum + score));
        visited[j] = 0;
    }
 
    return mx;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    cin >> N;
    a.assign(N, string());
    b.assign(N, string());
    visited.assign(N, 0);
    for (auto& s : a) cin >> s;
    for (auto& s : b) cin >> s;
 
    cout << go(N, 0, 0);
}
