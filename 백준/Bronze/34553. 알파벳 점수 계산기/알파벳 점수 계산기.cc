#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    string s; cin >> s;
    int sum = 1;
    int cnt = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i - 1] >= s[i]) cnt = 1;
        else cnt = cnt + 1;
        sum += cnt;
    }
    cout << sum;
}
