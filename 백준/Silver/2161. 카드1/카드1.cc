#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++) q.push(i + 1);

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
        q.push(q.front()); q.pop();
    }
}