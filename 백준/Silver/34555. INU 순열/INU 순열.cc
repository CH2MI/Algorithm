#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int N; cin >> N;
    int mid = N / 2 + 1;
 
    cout << mid << ' ';
    for (int i = 1; i <= N / 2; i++) {
        if (mid - i > 0) cout << mid - i << ' ';
        if (mid + i <= N) cout << mid + i << ' ';
    }
}
