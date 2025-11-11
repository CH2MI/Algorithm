#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    deque<int> q;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s == "push") {
            int X; cin >> X;
            q.push_back(X);
        }
        else if (s == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n', q.pop_front();
        }
        else if (s == "size") cout << q.size() << '\n';
        else if (s == "empty") cout << q.empty() << '\n';
        else if (s == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (s == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }

    }
}