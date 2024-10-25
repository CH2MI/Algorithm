#include <iostream>
#include <vector>
using namespace std;

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr); cout.tie(nullptr);
 
 int N;
 long long T;
 cin >> N >> T;
 vector<int> v(N), visited(N, -1);
 for (auto& i : v) cin >> i, --i;
 long long cnt = 0;
 int cur = 0;
 while (visited[cur] == -1 && cnt < T) {
    visited[cur] = cnt++;
    cur = v[cur];
 }
 if (cur < T) {
    long long t = cnt - visited[cur];
    cnt = (T - cnt) % t;
    while (cnt--) cur = v[cur];
 }
 cout << cur + 1;
}