#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int> pq;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        pq.push(-a);
    }

    int sum = 0;
    while (pq.size() > 1) {
        int a = -pq.top(); pq.pop();
        int b = -pq.top(); pq.pop();
        sum += a + b;
        pq.push(-(a + b));
    }
    cout << sum;
}